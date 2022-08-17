// https://leetcode.com/problems/palindrome-partitioning-iv

class Solution {
public:
    bool checkPartitioning(string s) {
        int m=s.length();
        bool pal[m][m];
        for(int i=0;i<m;i++){
            pal[i][i]=1;
            if((i+1)<m)
                pal[i][i+1]=(s[i]==s[i+1]);
        }
        for(int l=3;l<=m;l++){
            int i=0;
            int j=l-1;
            while(j<m){
                pal[i][j]=(s[i]==s[j]) && (pal[i+1][j-1]);
                i++;
                j++;
            }
        }
        for(int i=1;i<=(m-2);i++){
            for(int j=i;j<(m-1);j++){
                if(pal[0][i-1] && pal[i][j] && pal[j+1][m-1])
                    return true;
            }
        }
        return false;
    }
};