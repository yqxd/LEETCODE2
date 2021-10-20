//
// Created by lenovo on 2021/10/20.
//

//Given an array nums of size n, return the majority element.
//
//The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
//
//
//
//Example 1:
//
//Input: nums = [3,2,3]
//Output: 3
//Example 2:
//
//Input: nums = [2,2,1,1,1,2,2]
//Output: 2


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
    int majorityElement(vector<int> &nums) {
        int result[2] = {-1, 0};
        bool occupy = false;
        for (auto i: nums) {
            if (i == result[0]) {
                result[1] += 1;
            } else if (result[1] == 0) {
                result[1] += 1;
                result[0] = i;
            } else {
                result[1] -= 1;
            }
        }
        return result[0];
    }
};

int main() {
    vector<int> A = {1, 1, 3, 4};

}