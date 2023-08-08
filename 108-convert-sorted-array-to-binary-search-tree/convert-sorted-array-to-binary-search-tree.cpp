class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size() - 1);
    }
    
    TreeNode* constructBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }
        
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = constructBST(nums, left, mid - 1);
        root->right = constructBST(nums, mid + 1, right);
        
        return root;
    }
};
