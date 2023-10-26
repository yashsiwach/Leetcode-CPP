
class Solution {
const int MOD = 1e9 + 7;
public:
    int numFactoredBinaryTrees(std::vector<int>& arr) {
        // Step 1: Sort the input array.
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Create a set to store unique numbers in the array.
        std::unordered_set<int> uniqueNumbers(arr.begin(), arr.end());
        
        // Step 3: Initialize a dynamic programming map.
        std::unordered_map<int, int> dp;
        for (int num : arr) {
            dp[num] = 1;
        }
        
        // Step 4: Dynamic Programming
        for (int i : arr) {
            for (int j : arr) {
                // If j is larger than the square root of i, break the loop because further j values won't be factors.
                if (j > std::sqrt(i)) break;
                
                // Check if j is a factor of i and if i/j is in the set of unique numbers.
                if (i % j == 0 && uniqueNumbers.find(i / j) != uniqueNumbers.end()) {
                    long long temp = static_cast<long long>(dp[j]) * dp[i / j];
                    
                    // Update the number of binary trees ending with i based on the factors j and i/j.
                    if (i / j == j) {
                        dp[i] = (dp[i] + temp) % MOD;
                    } else {
                        dp[i] = (dp[i] + temp * 2) % MOD;
                    }
                }
            }
        }
        
        // Step 5: Calculate the final result.
        int result = 0;
        for (auto& [_, val] : dp) {
            result = (result + val) % MOD;
        }
        return result;
    }
};