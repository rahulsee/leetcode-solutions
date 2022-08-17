// https://leetcode.com/problems/design-twitter

class Twitter {
public:
    /** Initialize your data structure here. */
    
    unordered_map<int, set<pair<int, int>>>tweets;
    unordered_map<int, unordered_set<int > >follows;
    int counter;
    Twitter() {
        tweets.clear();
        follows.clear();
        counter=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].insert({tweetId, counter});
        counter++;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int> >all;
        vector<int>f(follows[userId].begin(), follows[userId].end());
        vector<pair<int,int>>t(tweets[userId].begin(), tweets[userId].end());
        for(pair<int,int>p: t)
            all.push_back(p);
        for(int i=0;i<f.size();i++){
            if(f[i]==userId)
                continue;
            vector<pair<int,int>>t(tweets[f[i]].begin(), tweets[f[i]].end());
            for(pair<int,int>p: t)
                all.push_back(p);
        }
        for(int i=0;i<min((int)all.size(),10);i++){
            for(int j=i+1;j<all.size();j++){
                if(all[i].second < all[j].second){
                    swap(all[i], all[j]);
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<min(10, (int)all.size());i++){
            ans.push_back(all[i].first);
        }
        return ans;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */