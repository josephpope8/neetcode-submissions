class Twitter {
private:
    vector<pair<int, int>> tweets;
    unordered_map<int, unordered_set<int>> follows;

public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int i = tweets.size() - 1;
        while(i >= 0 && feed.size() < 10){
            if(tweets[i].first == userId || follows[userId].count(tweets[i].first)){
                feed.push_back(tweets[i].second);
            }
            i--;
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
