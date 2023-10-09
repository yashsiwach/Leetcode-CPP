class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> v(2, -1); // Initialize with -1s
        
        // Find the first occurrence using lower_bound
        auto it = lower_bound(nums.begin(), nums.end(), target);
        
        // Check if target is not found
        if (it == nums.end() || *it != target) {
            return v;
        }
        
        v[0] = it - nums.begin();
        
        // Find the last occurrence using upper_bound
        auto it2 = upper_bound(nums.begin(), nums.end(), target);
        v[1] = it2 - nums.begin() - 1;
        
        return v;
    }
};
