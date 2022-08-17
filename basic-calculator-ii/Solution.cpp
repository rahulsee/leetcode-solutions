// https://leetcode.com/problems/basic-calculator-ii

class Solution {
public:
    
    int precedence(char ch){
        switch(ch)
        {
            case '+':
            case '-':
                return 1;
            case '*':
            case '/':
                return 2;
        }
        return numeric_limits<int>::min();
    }
    
    int apply(int a, int b, char ch){
        switch(ch)
        {
            case '+':
            return a+b;
            case '-':
            return a-b;
            case '/':
            return a/b;
            case '*':
            return a*b;
        }
        return 0;
    }
    
    int calculate(string s) {
        stack<char>st;
        stack<int>numst;
        int i=0;
        while(i<s.length()){
            if(s[i]>='0' && s[i]<='9'){
                string tmp;
                while(i<s.length() && s[i]>='0' && s[i]<='9'){
                    tmp.push_back(s[i]);
                    i++;
                }
                if(tmp.length()>0)
                    numst.push(stoi(tmp));
            }
            if(s[i]==' '){
                while(i<s.length() && s[i]==' ')
                    i++;
            }
            if(i<s.length() && (s[i]=='+' || s[i]=='-'|| s[i]=='/' || s[i]=='*')){
                while(!st.empty() && precedence(st.top()) >= precedence(s[i])){
                    char op=st.top();
                    st.pop();
                    int numB=numst.top();
                    numst.pop();
                    int numA=numst.top();
                    numst.pop();
                    // cout<<apply(numA, numB, op)<<endl;
                    numst.push(apply(numA, numB, op));
                }
                st.push(s[i]);
                i++;
            }
        }
        while(!st.empty()){
            char op=st.top();
            st.pop();
            int numB=numst.top();
            numst.pop();
            int numA=numst.top();
            numst.pop();
            // cout<<apply(numA, numB, op)<<endl;
            numst.push(apply(numA, numB, op));
        }
        return numst.top();
    }
};