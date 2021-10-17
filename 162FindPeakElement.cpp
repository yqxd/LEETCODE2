//
// Created by lenovo on 2021/10/17.
//

//A peak element is an element that is strictly greater than its neighbors.
//
//Given an integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.
//
//You may imagine that nums[-1] = nums[n] = -∞.
//
//You must write an algorithm that runs in O(log n) time.
//
//
//
//Example 1:
//
//Input: nums = [1,2,3,1]
//Output: 2
//Explanation: 3 is a peak element and your function should return the index number 2.
//Example 2:
//
//Input: nums = [1,2,1,3,5,6,4]
//Output: 5
//Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

#include <math.h>
#include <stdio.h>
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
    int find(vector<int> &nums, int begin, int mid, int end) {
        if (end - begin <= 2) {
            return mid;
        } else {
            if (nums[mid] < nums[mid - 1]) {
                return find(nums, begin, (begin + mid) / 2, mid);
            } else if (nums[mid] < nums[mid + 1]) {
                return find(nums, mid, (end + mid) / 2, end);
            } else {
                return mid;
            }
        }
    }

    int findPeakElement(vector<int> &nums) {
        nums.insert(nums.begin(), -1);
        nums.insert(nums.end(), -1);
        return find(nums, 0, (nums.size() - 1) / 2, nums.size() - 1) - 1;
    }
};