//
// Created by lenovo on 2021/10/10.
//

//Given an input string s, reverse the order of the words.
//
//A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
//
//Return a string of the words in reverse order concatenated by a single space.
//
//Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
//
//
//
//Example 1:
//
//Input: s = "the sky is blue"
//Output: "blue is sky the"
//Example 2:
//
//Input: s = "  hello world  "
//Output: "world hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//Example 3:
//
//Input: s = "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
//Example 4:
//
//Input: s = "  Bob    Loves  Alice   "
//Output: "Alice Loves Bob"
//Example 5:
//
//Input: s = "Alice does not even like bob"
//Output: "bob like even not does Alice"
//
//
//Constraints:
//
//1 <= s.length <= 104
//s contains English letters (upper-case and lower-case), digits, and spaces ' '.
//There is at least one word in s.


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + begin, s.begin() + i);
                begin = i + 1;
            }
        }
        reverse(s.begin() + begin, s.end());
        reverse(s.begin(), s.end());
        for (begin = 0; begin < s.size(); begin++) {
            if (s[begin] != ' ') {
                break;
            }
        }
        for (end = s.size() - 1; end >= begin; --end) {
            if (s[end] != ' ') {
                break;
            }
        }
        return s.substr(begin, end - begin + 1);
    }
};


int main() {
    string s = "keep an apple a dat";
    Solution A;
    cout << A.reverseWords(s) << endl;
}