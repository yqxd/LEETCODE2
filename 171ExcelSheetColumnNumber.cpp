//
// Created by lenovo on 2021/10/20.
//

//Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.
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
//Input: columnTitle = "A"
//Output: 1
//Example 2:
//
//Input: columnTitle = "AB"
//Output: 28
//Example 3:
//
//Input: columnTitle = "ZY"
//Output: 701
//Example 4:
//
//Input: columnTitle = "FXSHRXW"
//Output: 2147483647

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
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (auto c: columnTitle) {
            result = (result * 26 + c - 64);
        }
        return result;
    }
};


int main() {
    Solution A;
    cout << A.titleToNumber("AA");
}