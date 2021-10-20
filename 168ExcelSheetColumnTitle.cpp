//
// Created by lenovo on 2021/10/19.
//

//Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.
//
//For example:
//
//A -> 1
//B -> 2
//C -> 3
//...
//Z -> 26
//AA -> 27
//AB -> 28
//...
//
//
//Example 1:
//
//Input: columnNumber = 1
//Output: "A"
//Example 2:
//
//Input: columnNumber = 28
//Output: "AB"
//Example 3:
//
//Input: columnNumber = 701
//Output: "ZY"
//Example 4:
//
//Input: columnNumber = 2147483647
//Output: "FXSHRXW"

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
    string convertToTitle(int columnNumber) {
        int t;
        string ans = "";
        while (columnNumber > 0) {
            t = (columnNumber - 1) % 26 + 1;
            ans = (char) (t + 64) + ans;
            columnNumber = (columnNumber - t) / 26;
        }
        return ans;
    }
};

int main() {
    Solution A;
    cout << A.convertToTitle(702);
}



//1   A
//26  Z
//26*1 + 1  AA
//26*26 + 26 ZZ 702
//26*26 + 26 + 1 AAA


































