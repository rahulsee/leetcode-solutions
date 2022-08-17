// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.length();
        string ans;
        int lo=2*(numRows-2);
        int offset=2*(numRows-1);
        if(numRows==1){
            return s;
        }
        for(int i=0;i<numRows;i++){
            int j=i;
            while(j<n){
                ans.push_back(s[j]);
                if(lo>0 && (j+lo)<n && i>0 && i<(numRows-1)){
                    cout<<j+lo<<endl;
                    ans.push_back(s[j+lo]);
                }
                j+=offset;
            }
            if(i!=0 && i!=(numRows-1))
            lo-=2;
        }
        return ans;
    }
};