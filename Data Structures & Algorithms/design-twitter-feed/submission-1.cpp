class Twitter {
private:
    // priority queue stores {'timestamp', tweetId}.
    unordered_map<int, priority_queue<pair<int,int>>> feed;
    int time;
    vector<vector<bool>> follows;
    unordered_map<int,pair<int,int>> tweeted_by;
    unordered_map<int,vector<int>> tweets;

public:
    Twitter() {
        time = 0;
        follows = vector<vector<bool>>(501, vector<bool>(501, false)); // i follows j.
    }
    
    void postTweet(int userId, int tweetId) {
        time += 1;
        tweets[userId].push_back(tweetId);
        tweeted_by[tweetId] = {time,userId};
        for (int followerId = 1; followerId < follows.size(); followerId++) {
            if ((follows[followerId][userId] == true) || followerId == userId) {
                feed[followerId].push({time, tweetId});
            }
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        int k = 0;
        vector<int> answerFeed;
        vector<pair<int,int>> refillFeed;
        while (!(feed[userId].empty()) && (k < 10)) {
            pair<int,int> post = feed[userId].top();
            feed[userId].pop();
            refillFeed.push_back(post);
            answerFeed.push_back(post.second);
            k++;
        }
        // recency[userId] -= k;
        for (auto tweet : refillFeed) {
            feed[userId].push(tweet);
        }
        return answerFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (follows[followerId][followeeId] == true) return;
        follows[followerId][followeeId] = true;
        for (int tweet : tweets[followeeId]) {
            feed[followerId].push({tweeted_by[tweet].first, tweet});
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        if (follows[followerId][followeeId] == false) return;
        follows[followerId][followeeId] = false;
        auto feed_temp = feed[followerId];
        priority_queue<pair<int,int>> new_feed;
        while (!feed_temp.empty()) {
            auto [rec, tweetId] = feed_temp.top();
            if (!(tweeted_by[tweetId].second == followeeId)) new_feed.push({rec, tweetId});
            feed_temp.pop();
        }
        feed[followerId] = new_feed;
    }
};
