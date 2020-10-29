#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// Given a string S and a string T, count the number of distinct subsequences of
// S which equals T.

// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).

// It's guaranteed the answer fits on a 32-bit signed integer.

// Example 1:

// Input: S = "rabbbit", T = "rabbit"
// Output: 3
// Explanation:
// As shown below, there are 3 ways you can generate "rabbit" from S.
// (The caret symbol ^ means the chosen letters)

// rabbbit
// ^^^^ ^^
// rabbbit
// ^^ ^^^^
// rabbbit
// ^^^ ^^^
// Example 2:

// Input: S = "babgbag", T = "bag"
// Output: 5
// Explanation:
// As shown below, there are 5 ways you can generate "bag" from S.
// (The caret symbol ^ means the chosen letters)

// babgbag
// ^^ ^
// babgbag
// ^^    ^
// babgbag
// ^    ^^
// babgbag
//   ^  ^^
// babgbag
//     ^^^

// class Solution {
//    public:
//     int numDistinct(string s, string t) {
//         vector<vector<int>> result = {{s[0] == t[0]}};
//         for (int i = 1; i < s.size(); i++) {
//             result[0].push_back(result[0][i - 1] + (s[i] == t[0]));
//         }
//         for (int i = 1; i < t.size(); i++) {
//             result.push_back({0});
//             for (int j = 1; j < s.size(); j++) {
//                 result[i].push_back(result[i][j - 1] +
//                                     result[i - 1][j] * (t[i] == s[j]));
//             }
//         }
//         for (auto i : result) {
//             printf("\n");
//             for (auto j : i) {
//                 cout << j;
//             }
//         }
//         return result[t.size() - 1][s.size() - 1];
//     }
// };

class Solution {
   public:
    int numDistinct(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if (n1 == 0 && n2 == 0)
            return 1;
        if (n1 < n2) {
            return 0;
        }
        vector<vector<long> > dp(n1 + 1, vector<long>(n2 + 1, 0));
        for (int i = 0; i <= n1; i++) {
            for (int j = 0; j <= n2; j++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 1;
                } else if (i == 0) {
                    dp[i][j] = 0;
                } else if (j == 0) {
                    dp[i][j] = 1;
                } else {
                    if (s[i - 1] == t[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n1][n2];
    }
};

int main() {
    string s = "rabbbit", t = "rabbit";
    Solution A;
    A.numDistinct(s, t);

    system("Pause");
}