// Given an array of integers that is already sorted in ascending order, find
// two numbers such that they add up to a specific target number.

// The function twoSum should return indices of the two numbers such that they
// add up to the target, where index1 must be less than index2.

// Note:

// Your returned answers (both index1 and index2) are not zero-based.
// You may assume that each input would have exactly one solution and you may
// not use the same element twice. Example:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//    public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         for (int index2 = 2; index2 <= numbers.size(); index2++) {
//             if (numbers[index2 - 1] + numbers[0] > target) {
//                 break;
//             }
//             for (int index1 = 1; index1 < index2; index1++) {
//                 if (numbers[index1 - 1] + numbers[index2 - 1] == target) {
//                     return {index1, index2};
//                 } else if (numbers[index1 - 1] + numbers[index2 - 1] >
//                 target) {
//                     break;
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int index1 = 0, index2 = numbers.size() - 1;
        while (index2 > index1) {
            if (numbers[index2] + numbers[index1] > target) {
                index2--;
            } else if (numbers[index2] + numbers[index1] < target) {
                index1++;
            } else {
                break;
            }
        }
        return vector<int>{index1 + 1, index2 + 1};
    }
};

int main() {
    Solution A;
    vector<int> a = {2, 7, 11, 19};
    for (auto i: A.twoSum(a, 9))
        cout << i << endl;
    system("Pause");
}