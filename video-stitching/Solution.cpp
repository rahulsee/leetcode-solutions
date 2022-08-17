// https://leetcode.com/problems/video-stitching

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        vector<int>cover(101);
        for(int i=0;i<=T;i++)
            cover[i]=i;
        int len=0;
        for(int i=0;i<clips.size();i++){
            cover[clips[i][0]]=max(cover[clips[i][0]], clips[i][1]);
            len=max(len, clips[i][1]);
        }
        int ans=0;
        int max_cover=cover[0];
        int cur=-1;
        if(T==0)
            return 0;
        for(int i=0;i<=T;i++){
            if(i>cur){
                if(i>max_cover)
                    return -1;
                cur=max_cover;
                ans++;
            }
            max_cover=max(cover[i], max_cover);
        }
        return ans;
    }
};