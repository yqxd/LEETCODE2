#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8}, B;
    for (auto i : A)
        cout << i;
    printf("\n");
    std::reverse(A.begin(), A.end());
    for (auto i : A)
        cout << i;
    printf("\n");
    B.swap(A);
    for (auto i : B)
        cout << i;
    printf("\n");
    std::copy(A.begin(), A.end(), B.begin());
    for (auto i : B) {
        cout << i;
    }
    system("Pause");
}