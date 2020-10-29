#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

// There are N children standing in a line. Each child is assigned a rating
// value.

// You are giving candies to these children subjected to the following
// requirements:

// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// What is the minimum candies you must give?

// Example 1:

// Input: [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1,
// 2 candies respectively. Example 2:

// Input: [1,2,2]
// Output: 4
// Explanation: You can allocate to the first, second and third child with 1, 2,
// 1 candies respectively.
//              The third child gets 1 candy because it satisfies the above two
//              conditions.

class Solution {
   public:
    int candy(vector<int>& ratings) {
        vector<int> A = {};
        int now = 0, del = 0;
        while (1) {
            if (now == ratings.size()) {
                break;
            }
            if(ratings)
        }
        return accumulate(A.begin(), A.end(), 0);
    }
};

int main() {
    vector<int> a = {1, 2, 5, 8, 5, 9, 76, 4, 2, 1, 1};
    Solution A;
    vector<int> B = {1, 0, 2};
    printf("\n");
    cout << A.candy(B);
    system("Pause");
}