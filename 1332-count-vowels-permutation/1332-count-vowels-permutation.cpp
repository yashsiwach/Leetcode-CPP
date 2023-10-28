class Solution {
public:
    int solve(char ch, int n, vector<vector<int>>& dp) {
        const int MOD = 1000000007;
        if (n == 0) return 1;
        int result = 0;
        if (dp[ch][n] != -1) return dp[ch][n];
        if (ch == 'a') {
            result = (result + solve('e', n - 1, dp)) % MOD;
        }
        else if (ch == 'e') {
            result = (result + solve('a', n - 1, dp)) % MOD;
            result = (result + solve('i', n - 1, dp)) % MOD;
        }
        else if (ch == 'i') {
            result = (result + solve('a', n - 1, dp)) % MOD;
            result = (result + solve('e', n - 1, dp)) % MOD;
            result = (result + solve('o', n - 1, dp)) % MOD;
            result = (result + solve('u', n - 1, dp)) % MOD;
        }
        else if (ch == 'o') {
            result = (result + solve('i', n - 1, dp)) % MOD;
            result = (result + solve('u', n - 1, dp)) % MOD;
        }
        else if (ch == 'u') {
            result = (result + solve('a', n - 1, dp)) % MOD;
        }
        return dp[ch][n] = result;
    }
    
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(200, vector<int>(n + 1, -1));
        const int MOD = 1000000007;
        int result = 0;
        result = (result + solve('a', n - 1, dp)) % MOD;
        result = (result + solve('e', n - 1, dp)) % MOD;
        result = (result + solve('i', n - 1, dp)) % MOD;
        result = (result + solve('o', n - 1, dp)) % MOD;
        result = (result + solve('u', n - 1, dp)) % MOD;
        return result;
    }
};
