//
// Created by lenovo on 2021/3/5.
//

//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
//
//A palindrome string is a string that reads the same backward as forward.
//
//
//
//Example 1:
//
//Input: s = "aab"
//Output: [["a","a","b"],["aa","b"]]
//Example 2:
//
//Input: s = "a"
//Output: [["a"]]
//
//
//Constraints:
//
//1 <= s.length <= 16
//s contains only lowercase English letters.


#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        if (s.empty()) {
            return vector<vector<string>>{{}};
        } else {
            for (int index = 1; index <= s.size(); index++) {
                string t = s.substr(0, index);
                if (isPalindrome(t)) {
                    vector<vector<string>> locResult = partition(s.substr(index, s.size()));
                    for (const auto &num : locResult) {
                        result.push_back(num);
                        result[result.size() - 1].insert(result[result.size() - 1].begin(), t);
                    }
                }
            }
            return result;
        }
    }

    static bool isPalindrome(string s) {
        for (int index = 0; index < s.size() / 2; index++) {
            if (s[index] != s[s.size() - 1 - index]) {
                return false;
            }
        }
        return true;
    }

};

int main() {
//    int A = "abc";
//    auto B = toupper(A);
    string s = "hello";
    for (auto &i : s) //i是个引用 i到底引用的是什么？
        i = toupper(i); //改变成大写，影响s的值
    cout << s << endl; //s的值是 HELLO
}