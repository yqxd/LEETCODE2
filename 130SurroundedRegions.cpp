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

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        if (board.size() < 3 || board[0].size() < 3) {
            return;
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){

            }
        }
    }
    bool check(vector<vector<char>>& board, int i, int j, int k){
        if(i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1){
            return false;
        } 
    }
};