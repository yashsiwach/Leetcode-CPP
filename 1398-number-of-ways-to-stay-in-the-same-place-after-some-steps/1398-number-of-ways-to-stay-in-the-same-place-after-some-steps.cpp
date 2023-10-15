#include <vector>

class Solution {
public:
    long long solve(int step, int len, int i, vector<vector<long long>>& memo) {
        if (i < 0 || i >= len || step < 0) {
            return 0;
        }
        if (step == 0) {
            return (i == 0) ;
        }
        
        if (memo[step][i] != -1) {
            return memo[step][i];
        }

        long long opt1 = solve(step - 1, len, i, memo)% 1000000007;
        long long opt2 = solve(step - 1, len, i + 1, memo)% 1000000007;
        long long opt3 = solve(step - 1, len, i - 1, memo)% 1000000007;

        memo[step][i] = 1LL*(opt1 + opt2 + opt3) % 1000000007;
        return memo[step][i];
    }
//  long long solve(int step, int len, int i, vector<vector<long long>>& memo)
//  {
//      vector<vector<long long>> memo(steps + 1, vector<long long>(arrLen+1, -1));


//  }

    int numWays(int steps, int arrLen) {
        vector<vector<long long>> memo(steps + 1, vector<long long>(1000+1, -1));
        return (solve(steps, arrLen, 0, memo));
    }
};