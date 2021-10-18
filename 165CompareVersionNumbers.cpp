//
// Created by lenovo on 2021/10/18.
//

//Given two version numbers, version1 and version2, compare them.
//
//Version numbers consist of one or more revisions joined by a dot '.'. Each revision consists of digits and may contain leading zeros. Every revision contains at least one character. Revisions are 0-indexed from left to right, with the leftmost revision being revision 0, the next revision being revision 1, and so on. For example 2.5.33 and 0.1 are valid version numbers.
//
//To compare version numbers, compare their revisions in left-to-right order. Revisions are compared using their integer value ignoring any leading zeros. This means that revisions 1 and 001 are considered equal. If a version number does not specify a revision at an index, then treat the revision as 0. For example, version 1.0 is less than version 1.1 because their revision 0s are the same, but their revision 1s are 0 and 1 respectively, and 0 < 1.
//
//Return the following:
//
//If version1 < version2, return -1.
//If version1 > version2, return 1.
//Otherwise, return 0.
//
//
//Example 1:
//
//Input: version1 = "1.01", version2 = "1.001"
//Output: 0
//Explanation: Ignoring leading zeroes, both "01" and "001" represent the same integer "1".
//Example 2:
//
//Input: version1 = "1.0", version2 = "1.0.0"
//Output: 0
//Explanation: version1 does not specify revision 2, which means it is treated as "0".
//Example 3:
//
//Input: version1 = "0.1", version2 = "1.1"
//Output: -1
//Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0 < 1, so version1 < version2.
//Example 4:
//
//Input: version1 = "1.0.1", version2 = "1"
//Output: 1
//Example 5:
//
//Input: version1 = "7.5.2.4", version2 = "7.5.3"
//Output: -1


#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#include<vector>
#include "stack"
#include "map"

using namespace std;

class Solution {
public:
    int extract(string &version, int &index) {
        int num = 0;
        for (index = index; index < version.size(); index++) {
            if (version[index] == 46) {
                index += 1;
                break;
            } else {
                num = num * 10 + (version[index] - 48);
            }
        }
        return num;

    }

    int compareVersion(string version1, string version2) {
        int index1 = 0, index2 = 0, num1, num2;
        while (index1 < version1.size() || index2 < version2.size()) {
            num1 = extract(version1, index1);
            num2 = extract(version2, index2);
            if (num1 > num2) {
                return 1;
            } else if (num1 < num2) {
                return -1;
            }
        }
        return 0;
    }
};

int main() {
    string version1 = "1.01", version2 = "1.001.1";
    Solution A;
    cout << A.compareVersion(version1, version2);
}




































