//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Twitter {
  private:
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int timestamp = 0;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        if (tweets.count(userId))
            for (auto &t : tweets[userId])
                pq.push(t);

        for (auto &followee : followers[userId])
            if (tweets.count(followee))
                for (auto &t : tweets[followee])
                    pq.push(t);

        vector<int> res;
        while (!pq.empty() && res.size() < 10) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};


//{ Driver Code Starts.

int main() {
    Twitter obj;

    int total_queries;
    cin >> total_queries;
    while (total_queries--) {
        int query;
        cin >> query;

        // if query = 1, postTweet()
        // if query = 2, getNewsFeed()
        // if query = 3, follow()
        // if query = 4, unfollow()

        if (query == 1) {
            int userId, tweetId;
            cin >> userId >> tweetId;
            obj.postTweet(userId, tweetId);
        } else if (query == 2) {
            int userId;
            cin >> userId;
            vector<int> vec = obj.getNewsFeed(userId);
            for (int a : vec) cout << a << " ";
            cout << endl;
        } else if (query == 3) {
            int follower, followee;
            cin >> follower >> followee;
            obj.follow(follower, followee);
        } else {
            int follower, followee;
            cin >> follower >> followee;
            obj.unfollow(follower, followee);
        }
    }
    return 0;
}
// } Driver Code Ends