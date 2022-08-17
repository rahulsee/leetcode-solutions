// https://leetcode.com/problems/delete-columns-to-make-sorted

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int cnt=0;
        for(int j=0;j<A[0].size();j++){
            bool flag=false;
            for(int i=1;i<A.size();i++){
                if(A[i][j] < A[i-1][j]){
                    flag=true;   
                    break;
                }
            }
            if(flag==true)
                cnt++;
        }
        return cnt;
    }
};