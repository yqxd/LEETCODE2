// Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
// surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded
// region.

// Example:

// X X X X
// X O O X
// X X O X
// X O X X
// After running your function, the board should be:

// X X X X
// X X X X
// X X X X
// X O X X
// Explanation:

// Surrounded regions shouldn’t be on the border, which means that any 'O' on
// the border of the board are not flipped to 'X'. Any 'O' that is not on the
// border and it is not connected to an 'O' on the border will be flipped to
// 'X'. Two cells are connected if they are adjacent cells connected
// horizontally or vertically.

#include <cmath>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() < 3 || board[0].size() < 3) {
            return;
        } else {
            vector<vector<int>> stack;
            for (int i = 0; i < board[0].size(); i++) {
                if (board[0][i] == 'O') {
                    stack.push_back({0, i});
                }
                if (board[board.size() - 1][i] == 'O') {
                    stack.push_back({static_cast<int>(board.size() - 1), i});
                }
            }
            for (int i = 1; i < board.size() - 1; i++) {
                if (board[i][0] == 'O') {
                    stack.push_back({i, 0});
                }
                if (board[i][board[0].size() - 1] == 'O') {
                    stack.push_back({i, static_cast<int>((board[0].size() - 1))});
                }
            }
            while (not stack.empty()) {
                vector<int> M = stack[stack.size() - 1];
                stack.pop_back();
                board[M[0]][M[1]] = 'E';
                if (M[0] > 0) {
                    if (board[M[0] - 1][M[1]] == 'O') {
                        stack.push_back({static_cast<int>(M[0] - 1), M[1]});
                    }
                }
                if (M[0] < board.size() - 1) {
                    if (board[M[0] + 1][M[1]] == 'O') {
                        stack.push_back({static_cast<int>(M[0] + 1), M[1]});
                    }
                }
                if (M[1] > 0) {
                    if (board[M[0]][M[1] - 1] == 'O') {
                        stack.push_back({static_cast<int>(M[0]), M[1] - 1});
                    }
                }
                if (M[1] < board[0].size() - 1) {
                    if (board[M[0]][M[1] + 1] == 'O') {
                        stack.push_back({static_cast<int>(M[0]), M[1] + 1});
                    }
                }
            }
            for (int i = 0; i < board.size(); i++) {
                for (int j = 0; j < board[0].size(); j++) {
                    if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    } else if (board[i][j] == 'E') {
                        board[i][j] = 'O';
                    }
                }
            }
        }
    }
};

int main() {
    char A[4][6] = {{'X', 'O', 'X', 'O', 'X', 'O'},
                    {'O', 'X', 'O', 'X', 'O', 'X'},
                    {'X', 'O', 'X', 'O', 'X', 'O'},
                    {'O', 'X', 'O', 'X', 'O', 'X'}};
    vector<vector<char>> B;
    for (auto &i : A) {
        B.emplace_back();
        for (char j : i) {
            B[B.size() - 1].push_back(j);
        }
    }

    Solution C = Solution();
    for (auto &i : B) {
        cout << '\n';
        for (char j : i) {
            cout << j;
        }
    }
    C.solve(B);
    cout << '\n';
    for (auto &i : B) {
        cout << '\n';
        for (char j : i) {
            cout << j;
        }
    }
}