class Twitter {
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>> > posts;
    int time;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({time, tweetId});
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        following[userId].insert(userId); // insert themselves
        for(int follow : following[userId]){
            for(auto post: posts[follow]){
                minHeap.push(post);
                if(minHeap.size() > 10) minHeap.pop();
            }
        }

        vector<int> res;
        while(!minHeap.empty()){
            res.push_back(minHeap.top().second); minHeap.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
