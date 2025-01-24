#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& v, string& word, int k, vector<vector<bool>>& visi) {
        int n = v.size();
        int m = v[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || word[k] != v[i][j] || visi[i][j]) {
            return false;
        }
        if (k == word.size() - 1) {
            return true;
        }

        visi[i][j] = true;

        bool a = solve(i + 1, j, v, word, k + 1, visi);
        bool b = solve(i, j - 1, v, word, k + 1, visi);
        bool c = solve(i, j + 1, v, word, k + 1, visi);
        bool d = solve(i - 1, j, v, word, k + 1, visi);

        visi[i][j] = false;

        return a || b || c || d;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visi(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, board, word, 0, visi)) {
                    return true;
                }
            }
        }

        return false;
    }
};
