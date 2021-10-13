//
// Created by lenovo on 2021/10/13.
//

//Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
//
//It is guaranteed that the answer will fit in a 32-bit integer.
//
//A subarray is a contiguous subsequence of the array.
//
//
//
//Example 1:
//
//Input: nums = [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//
//Input: nums = [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//
//
//Constraints:
//
//1 <= nums.length <= 2 * 104
//-10 <= nums[i] <= 10
//The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

#include <iostream>
#include <string>
#include <algorithm>
#include "vector"

using namespace std;


class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int result[nums.size()][2];
        int lr[3];
        result[0][0] = nums[0];
        result[0][1] = nums[0];
        int max_num = nums[0];
        for (int i = 1; i <= nums.size() - 1; i++) {
            lr[0] = nums[i];
            lr[1] = result[i - 1][0] * nums[i];
            lr[2] = result[i - 1][1] * nums[i];
            result[i][0] = *min_element(lr, lr + 3);
            result[i][1] = *max_element(lr, lr + 3);
            max_num = max(max_num, result[i][1]);
        }
        return max_num;
    }
};

int main() {
    vector<int> nums = {-2, 0, -1};
    Solution A;
    cout << A.maxProduct(nums);
}