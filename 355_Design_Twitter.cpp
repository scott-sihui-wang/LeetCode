class Twitter {
public:
    vector<pair<int,int>>tweeterList;
    unordered_map<int,set<int>>followList;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweeterList.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int cnt=0;
        vector<int> ans;
        for(int i=tweeterList.size()-1;i>=0;i--){
            if(tweeterList[i].first==userId || followList[userId].find(tweeterList[i].first)!=followList[userId].end()){
                ans.push_back(tweeterList[i].second);
                cnt++;
            }
            if(cnt==10)break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
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