class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxi = 0;

        for (int i = 0; i < n1; ++i) {
            int count = 0;
            for (int j = 0; i + j < n1 && j < n2; ++j) {
                if (nums1[i + j] == nums2[j]) {
                    count++;
                    maxi = max(count, maxi);
                } else {
                    count = 0; // Reset count if elements don't match
                }
            }
        }

        for (int j = 0; j < n2; ++j) {
            int count = 0;
            for (int i = 0; j + i < n2 && i < n1; ++i) {
                if (nums2[j + i] == nums1[i]) {
                    count++;
                    maxi = max(count, maxi);
                } else {
                    count = 0; // Reset count if elements don't match
                }
            }
        }

        return maxi;
    }
};
