//
// Created by 刘新军 on 2018/6/26.
//

#include <iostream>
#include "Twitter.h"
using namespace std;

int main() {

    /**
     * ["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]
     * [[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]
     */
    leetcode::Twitter2 twitter;
    twitter.postTweet(1,5);
    twitter.getNewsFeed(1);
    twitter.follow(1,2);
    twitter.postTweet(2,6);
    twitter.getNewsFeed(1);
    twitter.unfollow(1,2);
    twitter.getNewsFeed(1);
    cout << "DONE" << endl;

    return 0;
}