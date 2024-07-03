#include <vector>
#include <algorithm>

class Solution {
public:
    int minDifference(std::vector<int>& nums) {
        int n = nums.size();
        // If there are less than 5 numbers, we can make them all the same with 3 moves.
        if (n < 5) return 0;
        // Sort the numbers so we can easily find the smallest and biggest ones.
        std::sort(nums.begin(), nums.end());
        // Calculate the possible differences if we change:
        int a = nums[n-4] - nums[0];  // the 3 biggest numbers
        int b = nums[n-3] - nums[1];  // the 2 biggest and the smallest number
        int c = nums[n-2] - nums[2];  // the biggest and the 2 smallest numbers
        int d = nums[n-1] - nums[3];  // the 3 smallest numbers
        // Return the smallest difference from these options.
        return std::min({a, b, c, d});
    }
};