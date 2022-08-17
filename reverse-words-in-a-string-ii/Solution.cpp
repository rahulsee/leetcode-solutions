// https://leetcode.com/problems/reverse-words-in-a-string-ii

class Solution {
public:
    void reverseWords(vector<char>& s) {
        int x=0;
        int y=s.size()-1;
        while(x<=y){
            swap(s[x], s[y]);
            x++;
            y--;
        }
        int i=0;
        int n=s.size();
        while(i<n){
            int j=i;
            while(i<n && s[i]!=' '){
                i++;
            }
            int p=j;
            int q=i-1;
            while(p<=q){
                char temp=s[p];
                s[p]=s[q];
                s[q]=temp;
                p++;
                q--;
            }
            while(i<n && s[i]==' ')
                i++;
        }
        
    }
};