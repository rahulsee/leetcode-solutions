// https://leetcode.com/problems/find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    
    int findCelebrity(int n) {
        int celeb=0;
        for(int i=0;i<n;i++){
            if(knows(celeb, i)){
                celeb=i;
            }
        }
        cout<<celeb<<endl;
        for(int i=0;i<n;i++){
            if(celeb!=i && (knows(celeb, i) || !knows(i, celeb)))
                return -1;
        }
        return celeb;
    }
};