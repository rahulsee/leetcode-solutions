// https://leetcode.com/problems/delete-operation-for-two-strings

class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs[word1.length()+1][word2.length()+1];
        memset(lcs, 0, sizeof(lcs));
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                if(word1[i-1]==word2[j-1]){
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else {
                    lcs[i][j]=max(lcs[i][j-1], lcs[i-1][j]);
                }
            }
        }
        return word1.length()+word2.length()-2*lcs[word1.length()][word2.length()];
    }
};