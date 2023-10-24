class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int first = nums[0];

        while (l < h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] < first) {
                h = mid;
            } else {
                l = mid + 1;
            }
        }

        // Check the values at indices l and h
        if (nums[l] < first) {
            return nums[l];
        } else if (nums[h] < first) {
            return nums[h];
        }

        // If neither l nor h contains the minimum, return the value at index 0
        return first;
    }
};
