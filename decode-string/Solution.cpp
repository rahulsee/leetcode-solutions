// https://leetcode.com/problems/decode-string

class Solution {
public:
    
    string decodeString(string s) {
        stack<string>st;
        for(int i=0;i<s.length();i++){
            if(s[i]>='0' && s[i]<='9'){
                string tmp;
                while(s[i]>='0' && s[i]<='9')
                {
                    tmp.push_back(s[i]);
                    i++;
                }
                st.push(tmp);
            }
            else {
                if(s[i]>='a' && s[i]<='z'){
                    st.push(string(1,s[i]));
                }
                if(s[i]==']'){
                    string operand=st.top();
                    st.pop();
                    int repeat=stoi(st.top());
                    st.pop();
                    string tmp;
                    while(repeat--){
                        tmp+=operand;
                    }
                    st.push(tmp);
                }
                while(1){
                    if(st.size()==1)
                        break;
                    string opB=st.top();
                    if(opB[0]>='0' && opB[0]<='9')
                        break;
                    st.pop();
                    string opA=st.top();
                    if(opA[0]>='0' && opA[0]<='9'){
                        st.push(opB);
                        break;
                    }
                    st.pop();
                    st.push(opA+opB);
                }
            }
        }
        return st.top();
    }
};