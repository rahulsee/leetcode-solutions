// https://leetcode.com/problems/string-compression

class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int n=chars.size();
        int k=0;
        while(i<n)
        {
            int j=i;
            int cnt=0;
            while(j<n && chars[i]==chars[j])
            {
                cnt++;
                j++;
            }
            if(cnt>1)
            {
                chars[k]=chars[i];
                k++;
                string strcount=to_string(cnt);
                for(char ch: strcount)
                {
                    chars[k]=ch;
                    k++;
                }
            }
            else 
            {
                chars[k]=chars[i];
                k++;
            }
            i=j;
        }
        return k;
        
    }
};