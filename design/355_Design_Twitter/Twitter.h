/*
设计一个简化版的推特(Twitter)，可以让用户实现发送推文，关注/取消关注其他用户，能够看见关注人（包括自己）的最近十条推文。你的设计需要支持以下的几个功能：

    postTweet(userId, tweetId): 创建一条新的推文
    getNewsFeed(userId): 检索最近的十条推文。每个推文都必须是由此用户关注的人或者是用户自己发出的。推文必须按照时间顺序由最近的开始排序。
    follow(followerId, followeeId): 关注一个用户
    unfollow(followerId, followeeId): 取消关注一个用户

示例:

Twitter twitter = new Twitter();

// 用户1发送了一条新推文 (用户id = 1, 推文id = 5).
twitter.postTweet(1, 5);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
twitter.getNewsFeed(1);

// 用户1关注了用户2.
twitter.follow(1, 2);

// 用户2发送了一个新推文 (推文id = 6).
twitter.postTweet(2, 6);

// 用户1的获取推文应当返回一个列表，其中包含两个推文，id分别为 -> [6, 5].
// 推文id6应当在推文id5之前，因为它是在5之后发送的.
twitter.getNewsFeed(1);

// 用户1取消关注了用户2.
twitter.unfollow(1, 2);

// 用户1的获取推文应当返回一个列表，其中包含一个id为5的推文.
// 因为用户1已经不再关注用户2.
twitter.getNewsFeed(1);



 */

#ifndef LEETCODE_TWITTER_H
#define LEETCODE_TWITTER_H

#include <iostream>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <deque>
#include <vector>
using namespace std;
namespace leetcode {
    class Twitter {
    public:
        /** Initialize your data structure here. */
        Twitter() {
            id = 0;
        }

        /** Compose a new tweet. */
        void postTweet(int userId, int tweetId) {
            id++;
            auto temp = std::make_pair(id, tweetId);
            auto feed = std::make_pair(userId, temp);
            feeds.push_front(feed);
        }

        /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
        vector<int> getNewsFeed(int userId) {
            vector<int> res;
            initFollowers(userId);
            int count = 0;
            for (auto iter = feeds.cbegin(); iter != feeds.cend(); ++iter) {
                if (_relation[userId].count(iter->first)) {
                    res.push_back(iter->second.second);
                    ++count;
                }
                if (count >= 10) break;
            }
            return res;
        }

        /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
        void follow(int followerId, int followeeId) {
            initFollowers(followerId);
            _relation[followerId].insert(followeeId);
        }

        /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
        void unfollow(int followerId, int followeeId) {
            if (!_relation.count(followerId)) return;
            _relation[followerId].erase(followeeId);
        }

    private:
        void initFollowers(int followerId) {
            if (_relation.count(followerId)) return;
            _relation[followerId] = std::unordered_set<int>();
            _relation[followerId].insert(followerId);
        }

    private:
        unordered_map<int, unordered_set<int> > _relation;
        deque<std::pair<int, std::pair<int, int>>> feeds;
        unsigned int id;
    };
};

namespace leetcode {
class Twitter2 {
public:
    typedef deque<pair<int, int>> dPair;
    /** Initialize your data structure here. */
    Twitter2() = default;

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        ++_seq;
        if(!_queues.count(userId)) _queues[userId] = dPair();
        _queues[userId].emplace_front(make_pair(_seq, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        initFollow(userId);
        auto followers = _r[userId];
        map<int, int> _m;
        for(auto iter = followers.begin(); iter != followers.end(); ++iter) {
            auto& _q = _queues[*iter];
            int c = 0;
            for(auto iter1 = _q.cbegin(); c < _fetchSize && iter1 != _q.cend(); ++iter1 ) {
                ++c;
                int seq = iter1->first;
                int tweetId = iter1->second;
                _m.insert(make_pair(seq, tweetId));
                if (_m.size() > _fetchSize) {
                    _m.erase(_m.begin());
                }
            }
        }
        for(auto iter = _m.crbegin(); iter != _m.crend(); ++iter) {
            res.push_back(iter->second);
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        initFollow(followerId);
        _r[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (!_r.count(followerId)) return;
        _r[followerId].erase(followeeId);
    }

private:
    void initFollow(int userId) {
        _r[userId].insert(userId);
    }
    const int _fetchSize = 10;
    unsigned int _seq = 0;
    unordered_map<int, unordered_set<int>> _r;
    unordered_map<int, dPair> _queues;
};
};

#endif //LEETCODE_TWITTER_H
