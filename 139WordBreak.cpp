//
// Created by lenovo on 2021/9/25.
//

//Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
//
//Note that the same word in the dictionary may be reused multiple times in the segmentation.
//
//
//
//Example 1:
//
//Input: s = "leetcode", wordDict = ["leet","code"]
//Output: true
//Explanation: Return true because "leetcode" can be segmented as "leet code".
//Example 2:
//
//Input: s = "applepenapple", wordDict = ["apple","pen"]
//Output: true
//Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//Note that you are allowed to reuse a dictionary word.
//Example 3:
//
//Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
//Output: false


#include <cstdio>
#include <iostream>
#include <cstring>
#include "string"
#include "vector"
#include "hashtable.h"
#include "map"


using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        bool breakable[s.length() + 1];
        memset(breakable, false, sizeof(breakable));
        map<string, bool> M;
        for (string s:wordDict) {
            M[s] = true;
        }
        breakable[0] = true;
        for (int end = 1; end <= s.length(); end++) {
            for (int begin = 0; begin < end; begin++) {
                if (breakable[begin] && M.find(s.substr(begin, end - begin)) != M.end()) {
                    breakable[end] = true;
                    break;
                }
            }
        }
        return breakable[s.length()];
    }
};

int main() {
    Solution A;
    string s = "applepenapple";
    vector<string> wordDict = {"apple","pen","and","cat"};
    printf("%d", A.wordBreak(s, wordDict));
}