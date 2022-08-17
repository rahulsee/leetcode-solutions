// https://leetcode.com/problems/alien-dictionary

class Solution {
public:
    
    stack<int>st;
    vector<bool>visited;
    string ans;
    int mat[26][26];
    
     bool findDiff(string a, string b, char &x, char &y){
         int m=a.length();
         int n=b.length();
         for(int i=0;i<min(m,n);i++){
             if(a[i]!=b[i]){
                 x=a[i];
                 y=b[i];
                 break;
             }
         }
         if(x==0 && y==0 && m>n){
             return false;
         }
         return true;
     }
    
     void dfs(int cur){
         visited[cur]=true;
         for(int i=0;i<26;i++){
             if(mat[cur][i] && !visited[i]){
                dfs(i);
             }
         }
         st.push(cur);
     }
    
     string alienOrder(vector<string>& words) {
        vector<bool>tmp(26, false);
        visited=tmp;
        int size=words.size();
        memset(mat, 0, sizeof(mat));
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                char x=0, y=0;
                if(!findDiff(words[i], words[j], x,y)){
                    return "";
                }
                if(x && y){
                    mat[x-97][y-97]=true;
                    if(mat[y-97][x-97])
                        return "";
                }
            }
        }
        
       for(int i=0;i<size;i++){
             for(char ch: words[i]){
                 if(!visited[ch-97]){
                     dfs(ch-97);
                 }
             }
        }
        while(!st.empty()){
            ans.push_back(st.top()+97);
            st.pop();
        }
        
        return ans;
    }
    
};