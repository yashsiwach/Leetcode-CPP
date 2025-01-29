#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string a, string b, string c) {
        if(a.size() + b.size() != c.size()) return false;
        
        vector<vector<bool>> dp(a.size() + 1, vector<bool>(b.size() + 1, false));

        dp[0][0] = true;

        for(int i = 1; i <= a.size(); i++) {
            dp[i][0] = dp[i - 1][0] && (a[i - 1] == c[i - 1]);
        }

        for(int j = 1; j <= b.size(); j++) {
            dp[0][j] = dp[0][j - 1] && (b[j - 1] == c[j - 1]);
        }

        for(int i = 1; i <= a.size(); i++) {
            for(int j = 1; j <= b.size(); j++) {
                int k = i + j - 1;
                if(a[i - 1] == c[k]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                }
                if(b[j - 1] == c[k]) {
                    dp[i][j] = dp[i][j] || dp[i][j - 1];
                }
            }
        }

        return dp[a.size()][b.size()];
    }
};
