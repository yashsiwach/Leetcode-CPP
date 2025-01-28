
class Solution {
public:
    vector<vector<vector<int>>> dp;

    bool rec(string a, string b, string c, int i, int j, int k) {
        if(k == c.size()) {
            return i == a.size() && j == b.size();
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool e = false;
        bool f = false;

        if(i < a.size() && a[i] == c[k]) {
            e = rec(a, b, c, i + 1, j, k + 1);
        }

        if(j < b.size() && b[j] == c[k]) {
            f = rec(a, b, c, i, j + 1, k + 1);
        }

        return dp[i][j][k] = (e || f);
    }

    bool isInterleave(string a, string b, string c) {

        dp.resize(a.size() + 1, vector<vector<int>>(b.size() + 1, vector<int>(c.size() + 1, -1)));
        return rec(a, b, c, 0, 0, 0);
    }
};
