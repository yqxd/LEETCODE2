//
// Created by lenovo on 2021/3/10.
//

//Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
//
//
//
//Example 1:
//
//Input: nums = [2,2,3,2]
//Output: 3
//Example 2:
//
//Input: nums = [0,1,0,1,0,1,99]
//Output: 99
//
//
//Constraints:
//
//1 <= nums.length <= 3 * 104
//-231 <= nums[i] <= 231 - 1
//Each element in nums appears exactly three times except for one element which appears once.
//
//
//Follow up: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int singleNumber(vector<int>
                            &nums) {
        int ones = 0;
        int tows = 0;
        for (int i = 0; i < nums.size(); i++) {
            ones = (ones ^ nums[i]) & (~tows);
            tows = (tows ^ nums[i]) & (~ones);
        }
        return ones;
    }
};

int main() {
    vector<int> A = {1, 3, 3, 3};
    cout << Solution::singleNumber(A);
}