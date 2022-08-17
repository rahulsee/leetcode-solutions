// https://leetcode.com/problems/score-of-parentheses

#define CHAR 1
#define INT 2
class Solution {
public:
    struct node {
        int type;
        int data;
        node(int d, int t){
            data=d;
            type=t;
        }
    };
    
    int scoreOfParentheses(string S) {
        int score=0;
        stack<node>st;
        for(char ch: S){
           if(ch=='(' || st.empty()){
               st.push(node('(', CHAR));
           }
           else if(ch==')'){
               if(st.top().data=='(' && st.top().type==CHAR){
                   st.pop();
                   st.push(node(1, INT));
               }
               else {
                   int t=0;
                   bool flag=true;
                  while(!st.empty() && st.top().type==INT){
                      t+=st.top().data;
                      st.pop();
                      flag=false;
                  }
                   st.pop();
                   if(flag==true) {
                       st.push(node(1, INT));
                   }
                   else {
                       st.push(node(t*2, INT));
                   }
               }
           }
            else if(ch>='0' && ch<='9'){
                if(st.top().data==INT){
                    node x=st.top();
                    st.pop();
                    st.push(node(x.data+ch-'0', INT));
                }
                else {
                    st.push(node(ch-'0', INT));
                }
            }
        }
        while(!st.empty()){
            score+=(st.top().data);
            st.pop();
        }
        return score;
    }
};