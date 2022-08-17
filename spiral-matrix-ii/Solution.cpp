// https://leetcode.com/problems/spiral-matrix-ii

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>> ans(n, vector<int>(n));
        int i = 1;
        int x = 0, y = 0;
        int k = n - 1;
        for( ; k > 0; k -= 2){
            for(int j = 0; j < k; ++j)
                ans[x][y++] = i++;
            for(int j = 0; j < k; ++j)
                ans[x++][y] = i++;
            for(int j = 0; j < k; ++j)
                ans[x][y--] = i++;
            for(int j = 0; j < k; ++j)
                ans[x--][y] = i++;
            ++x;
            ++y;
        }
        if(k == 0) ans[x][y] = i;
        return ans;
    }
};