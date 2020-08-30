#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Given a triangle, find the minimum path sum from top to bottom. Each step you
// may move to adjacent numbers on the row below.

// For example, given the following triangle

// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

// Note:

// Bonus point if you are able to do this using only O(n) extra space, where n
// is the total number of rows in the triangle.

class Solution {
   public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++) {
            triangle[i][0] += triangle[i - 1][0];
            triangle[i][i] += triangle[i - 1][i - 1];
            for (int j = 1; j <= i - 1; j++) {
                triangle[i][j] +=
                    min(triangle[i - 1][j - 1], triangle[i - 1][j]);
            }
        }
        for (auto i : triangle) {
            for (auto j : i)
                cout << j << endl;
        }
        return *min_element(triangle[triangle.size() - 1].begin(),
                            triangle[triangle.size() - 1].end());
    }
};

int main() {
    vector<vector<int>> triangle = {{1}, {2, 3}, {1, 4, 6}, {3, 5, 1, 7}};
    Solution A;
    cout << A.minimumTotal(triangle) << endl;
    system("Pause");
}