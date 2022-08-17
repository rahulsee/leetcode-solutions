// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order

class Solution {
public:
    
    int getindex(char ch){
        switch(ch){
            case 'a':
                return 0;
            case 'e':
                return 1;
            case 'i':
                return 2;
            case 'o':
                return 3;
            case 'u':
                return 4;
        }
        return -1;
    }
    
    int longestBeautifulSubstring(string word) {
        int i=0;
        int n=word.length();
        int maxi=0;
        while(i<n){
            int cnt[5]={0,0,0,0,0};
            int ans=1;
            cnt[getindex(word[i])]++;
            if((i+1)<n && word[i]<=word[i+1]){
                while((i+1)<n && word[i]<=word[i+1]){
                    i++;
                    ans++;
                    cnt[getindex(word[i])]++;
                }
                if(cnt[0] && cnt[1] && cnt[2] && cnt[3] && cnt[4]){
                    maxi=max(ans, maxi);
                }
            }
            else 
                i++;
        }
        return maxi;
    }
};