//
// Created by lenovo on 2021/10/21.
//

//Given an integer n, return the number of trailing zeroes in n!.
//
//Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.
//
//
//
//Example 1:
//
//Input: n = 3
//Output: 0
//Explanation: 3! = 6, no trailing zero.
//Example 2:
//
//Input: n = 5
//Output: 1
//Explanation: 5! = 120, one trailing zero.
//Example 3:
//
//Input: n = 0
//Output: 0

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
    int trailingZeroes(int n) {
        if (n < 5) {
            return 0;
        } else {
            return n / 5 + trailingZeroes(n / 5);
        }
    }
};