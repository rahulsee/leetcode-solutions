// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:  
    int minDifficulty(vector<int>& arr, int d) {
        int n=arr.size();
        int maxdp[n][n];
        memset(maxdp, 0, sizeof(maxdp));
        for(int i=0;i<n;i++){
            maxdp[i][i]=arr[i];
            if((i+1)<n){
                maxdp[i][i+1]=max(arr[i], arr[i+1]);
            }
        }
        for(int l=3;l<=n;l++){
            int i=0;
            int j=l-1;
            while(j<n){
                maxdp[i][j]=max(maxdp[i][j-1], maxdp[i+1][j]);
                i++;
                j++;
            }
        }
        int dp[n][n][d+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<=d;k++){
                    dp[i][j][k]=300*1000+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j][1]=maxdp[i][j];
            }
        }
        
        for(int p=2;p<=d;p++){
            for(int l=2;l<=n;l++){
                int i=0;
                int j=l-1;
                while(j<n){
                    dp[i][j][p]=numeric_limits<int>::max();
                    for(int k=i;k<j;k++){
                        dp[i][j][p]=min(dp[i][j][p], dp[i][k][p-1]+maxdp[k+1][j]);
                    }
                    j++;
                    i++;
                }
            }
        }
        
        return (dp[0][n-1][d]>(300*1000+1)?-1:dp[0][n-1][d]);
    }
};