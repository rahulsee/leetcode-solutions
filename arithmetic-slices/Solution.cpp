// https://leetcode.com/problems/arithmetic-slices

int dp[10001][10001];
int cd[10001][10001];
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int MAXI=numeric_limits<int>::max();
        if(A.size()==0)
            return 0;
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cd[i][j]=dp[i][j]=MAXI;
            }
        }
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        for(int i=1;i<n;i++){
            dp[i-1][i]=2;
        }
        for(int i=0;i<n;i++)
            cd[i][i]=0;
        for(int i=1;i<n;i++){
            cd[i-1][i]=(A[i]-A[i-1]);
        }
        int ans=0;
        for(int l=3;l<=n;l++){
            int i=0;
            int j=l-1;
            while(j<n){
                if(cd[i][j-1]==cd[i+1][j] && dp[i][j-1]==(j-i) && dp[i+1][j]==(j-i)){
                    ans++;
                    dp[i][j]=j-i+1;
                }
                else {
                    dp[i][j]=MAXI;
                    cd[i][j]=MAXI;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};