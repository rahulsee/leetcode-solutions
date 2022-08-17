// https://leetcode.com/problems/reverse-integer

class Solution {
public:
    int reverse(int x) {
       
       int mini=numeric_limits<int>::min();
       int maxi=numeric_limits<int>::max();
       string strMini=to_string(mini).substr(1);
       string strMaxi=to_string(maxi);
       
       string strX=to_string(x);
       
       if(x<0)
       {
           string mag=strX.substr(1);
           ::reverse(mag.begin(), mag.end());
           if(mag.length() < strMini.length())
           {
                return -stoi(mag);
           }
           else if(mag <= strMini)
           {
               int y=-(mag[0]-'0');
               for(int i=1;i<mag.length();i++)
                   y=y*10-(mag[i]-'0');
               return y;
           }
           else
               return 0;
       }
       else 
       {
           ::reverse(strX.begin(), strX.end());
           if(strX.length() < strMaxi.length())
               return stoi(strX);
           else if(strX <= strMaxi)
               return stoi(strX);
           else
               return 0;
       }
    }
};