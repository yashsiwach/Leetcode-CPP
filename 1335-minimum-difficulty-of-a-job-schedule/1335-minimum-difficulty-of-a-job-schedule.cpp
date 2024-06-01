#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int solve(vector<int>& v, int n, int d, int ind, vector<vector<int>>& memo) {
        if (d == 1) {
            int maxi = 0;
            for (int i = ind; i < n; i++) {
                maxi = max(v[i], maxi);
            }
            return maxi;
        }
        
        if (memo[ind][d] != -1) return memo[ind][d];
        
        int less = INT_MAX, maxi = 0;
        for (int i = ind; i <= n - d; i++) {
            maxi = max(maxi, v[i]);
            int result = maxi + solve(v, n, d - 1, i + 1, memo);
            less = min(less, result);
        }
        
        return memo[ind][d] = less;
    }
    
    int minDifficulty(vector<int>& v, int d) {
        int n = v.size();
        if (d > n) return -1;
        vector<vector<int>> memo(n, vector<int>(d + 1, -1));
        int ans = solve(v, n, d, 0, memo);
        return ans;
    }
};
