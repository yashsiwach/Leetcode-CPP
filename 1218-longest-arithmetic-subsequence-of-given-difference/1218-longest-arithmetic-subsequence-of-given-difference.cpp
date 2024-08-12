class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int ans = 0; // Variable to store the maximum length of the subsequence
        unordered_map<int, int> dp; // Map to store the dynamic programming values
        
        for (int i = 0; i < arr.size(); i++) {
            int cnt = 0; // Counter to keep track of the subsequence length
            
            if (dp.count(arr[i] - difference)) {
                // If the previous element in the subsequence exists
                // (current element minus the difference) in the map,
                // retrieve its count
                cnt = dp[arr[i] - difference];
            }
            
            dp[arr[i]] = 1 + cnt; // Update the current element's count in the map
            ans = max(ans, dp[arr[i]]); // Update the maximum length if necessary
        }
        
        return ans; // Return the maximum length of the subsequence
    }
};