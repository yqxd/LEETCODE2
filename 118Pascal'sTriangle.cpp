// Given a non-negative integer numRows, generate the first numRows of Pascal's
// triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly
// above it.

// Example:

// Input: 5
// Output:
// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result = {};
        if (numRows == 0) {
            return result;
        }
        result.push_back({1});
        for (int i = 1; i < numRows; i++) {
            result.push_back({});
        }
        for (int i = 1; i < numRows; i++) {
            result[i].push_back(1);
            for (int j = 1; j <= i - 1; j++) {
                result[i].push_back(result[i - 1][j - 1] + result[i - 1][j]);
            }
            result[i].push_back(1);
        }
        return result;
    }
};

int main() {}