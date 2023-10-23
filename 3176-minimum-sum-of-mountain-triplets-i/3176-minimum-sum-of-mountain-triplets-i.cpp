class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int sum = INT_MAX;
        int n = nums.size();
        
        for (int i = 1; i < n - 1; i++) {
            int left = *min_element(nums.begin(), nums.begin() + i);
            int right = *min_element(nums.begin() + i, nums.end());
            
            if (nums[i] > left && nums[i] > right) {
                int s = nums[i] + left + right;
                sum = min(sum, s);
            }
            cout << i << " " << left << " " << right << " " << sum << endl;
        }
        
        return sum == INT_MAX ? -1 : sum;
    }
};
