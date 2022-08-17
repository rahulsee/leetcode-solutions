// https://leetcode.com/problems/splitting-a-string-into-descending-consecutive-values

class Solution {
public:
    
    string str;
    
    bool solve(int j, unsigned long long target){
        if(j==str.length())
            return true;
        unsigned long long sum=0;
        for(int x=j;x<str.length();x++){
            sum=sum*10+(str[x]-'0');
            if(sum==target && solve(x+1, target-1)){
                return true;
            }
        }
        return false;
    }
    
    bool splitString(string s) {
        str=s;
        int n=s.length();
        unsigned long long sum=0;
        for(int i=0;i<n-1;i++){
            sum=sum*10+(str[i]-'0');
            if(sum>0){
                if(solve(i+1, sum-1))
                    return true;
            }
        }
        return false;
    }
};