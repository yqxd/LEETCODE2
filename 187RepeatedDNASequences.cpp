//
// Created by lenovo on 2021/11/3.
//
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
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int n = s.size();
        for (int i = 0; i <= n - 10; i++) {
            string subDna;
            for (int j = i; j < i + 10; j++) {
                subDna += s[j];
            }
            mp[subDna]++;
        }
        vector<string> ans;
        for (auto i: mp) {
            if (i.second > 1) {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};