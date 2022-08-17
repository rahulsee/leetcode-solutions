// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int> >vec(strs.size());
        for(int i=0;i<strs.size();i++){
            vec[i].first=vec[i].second=0;
            for(int j=0;j<strs[i].length();j++){
                if(strs[i][j]=='0'){
                    vec[i].first++;
                }
                else {
                    vec[i].second++;
                }
            }
        }
      
        int dp[vec.size()+1][m+1][n+1];
        for(int i=0;i<=vec.size();i++){
            for(int j=0;j<=m;j++){
                for(int k=0;k<=n;k++){
                    dp[i][j][k]=numeric_limits<int>::max();
                }
            }
        }
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                dp[0][i][j]=0;
            }
        }
        
        for(int i=0;i<=vec.size();i++){
            dp[i][0][0]=0;
        }
        
        int ans=0;
        for(int k=1;k<=vec.size();k++){
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(i>=vec[k-1].first && j>=vec[k-1].second){
                        dp[k][i][j]=max(dp[k-1][i][j], dp[k-1][i-vec[k-1].first][j-vec[k-1].second]+1);
                    }
                    else {
                        dp[k][i][j]=dp[k-1][i][j];
                    }
                    ans=max(ans, dp[k][i][j]);
                }
            }
        }
        return ans;
    }
};