#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
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
        if (ratings.size() <= 2) {
            if (ratings.size() == 1) {
                return 1;
            } else if (ratings.size() == 0) {
                return 0;
            } else if (ratings[0] != ratings[1]) {
                return 3;
            } else {
                return 2;
            }
        }
        ratings.insert(ratings.begin(), ratings[0]);
        ratings.insert(ratings.end(), ratings[ratings.size() - 1]);
        vector<int> A = {0};
        for (int i = 1; i < ratings.size() - 1; i++) {
            if (ratings[i] <= ratings[i - 1] && ratings[i] <= ratings[i + 1]) {
                A.push_back(i);
            }
        }
        for (auto i : A) {
            ratings[i] = 1;
        }
        for (auto i : ratings)
            cout << i;
        for (auto i : A)
            cout << i;
        printf("\n");
        A.push_back(ratings.size() - 1);
        for (int i = 0; i < A.size() - 1; i++) {
            for (auto i : ratings)
                cout << i;
            printf("\n");
            alter(&A, ratings[i], ratings[i + 1]);
        }
        int sum = 0;
        for (int i = 1; i < ratings.size() - 1; i++) {
            sum += ratings[i];
        }
        return sum;
    }
    int alter(vector<int>* ratings, int a, int b) {
        int left = a + 1, right = b - 1;
        while (right > left && ratings->at(left) > ratings->at(a) &&
               ratings->at(right) > ratings->at(b)) {
            ratings->at(left) = ratings->at(a) + 1;
            ratings->at(right) = ratings->at(b) + 1;
            left++;
            a++;
            right--;
            b--;
        }
        while (right > left && ratings->at(left) > ratings->at(a)) {
            ratings->at(left) = ratings->at(a) + 1;
            left++;
            a++;
        }
        while (right > left && ratings[right] > ratings[b]) {
            ratings->at(right) = ratings->at(b) + 1;
            right--;
            b--;
        }
        if (right == left) {
            ratings->at(right) = ratings->at(b) + 1;
        }
        for (auto i : *ratings)
            cout << i;
        printf("\n");
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