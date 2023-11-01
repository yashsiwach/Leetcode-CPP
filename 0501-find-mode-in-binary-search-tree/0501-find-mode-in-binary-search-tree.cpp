class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> inorderr;
        inorder(root, inorderr);
        unordered_map<int, int> freq;
        int maxx = 0;
        
        for (int val : inorderr) {
            freq[val]++;
            maxx = max(maxx, freq[val]);
        }
        
        vector<int> result;
        for (const auto& pair : freq) {
            if (pair.second == maxx) {
                result.push_back(pair.first);
            }
        }
        
        return result;
    }

private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (!root) return;
        result.push_back(root->val);
        inorder(root->left, result);
        inorder(root->right, result);
    }
};