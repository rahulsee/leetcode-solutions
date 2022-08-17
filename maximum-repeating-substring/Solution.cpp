// https://leetcode.com/problems/maximum-repeating-substring

class Solution {
public:
    string multiply(string word, int f){
        string ans;
        for(int i=0;i<f;i++)
            ans+=word;
        return ans;
    }
    int maxRepeating(string sequence, string word) {
        int low=1;
        int high=sequence.length()/word.length()+1;
        int maxi=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            string s=multiply(word, mid);
            if(sequence.find(s)==string::npos){
                high=mid-1;
            }
            else {
                maxi=max(mid, maxi);
                low=mid+1;
            }
        }
        return maxi;
    }
};