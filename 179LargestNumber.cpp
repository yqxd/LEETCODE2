//
// Created by lenovo on 2021/10/25.
//

//Given a list of non-negative integers nums, arrange them such that they form the largest number.
//
//Note: The result may be very large, so you need to return a string instead of an integer.
//
//
//
//Example 1:
//
//Input: nums = [10,2]
//Output: "210"
//Example 2:
//
//Input: nums = [3,30,34,5,9]
//Output: "9534330"
//Example 3:
//
//Input: nums = [1]
//Output: "1"
//Example 4:
//
//Input: nums = [10]
//Output: "10"

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include<queue>
#include<vector>
#include "stack"
#include "map"
#include "string"

using namespace std;

class Solution {
public:
    static bool comp(int a, int b)//to compare and find the lexographically greater number.
    {
        string a1 = to_string(a) + to_string(b);
        string a2 = to_string(b) + to_string(a);
        return a1 > a2;
    }

    string largestNumber(vector<int> &nums) {
        string ans = "";
        sort(nums.begin(), nums.end(), comp);
        for (int num : nums)
            ans += to_string(num);
        if (nums[0] == 0)
            return "0";
        return ans;
    }
};

int main() {
    Solution A;
    vector<int> B = {564, 4, 56, 44, 12};
    cout << A.largestNumber(B);
}