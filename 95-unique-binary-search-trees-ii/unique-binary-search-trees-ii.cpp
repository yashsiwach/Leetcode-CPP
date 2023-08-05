class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return n ? generate_trees(1, n) : vector<TreeNode*>();
    }

private:
    vector<TreeNode*> generate_trees(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> all_trees;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left_trees = generate_trees(start, i - 1);
            vector<TreeNode*> right_trees = generate_trees(i + 1, end);

            for (TreeNode* l : left_trees) {
                for (TreeNode* r : right_trees) {
                    TreeNode* current_tree = new TreeNode(i);
                    current_tree->left = l;
                    current_tree->right = r;
                    all_trees.push_back(current_tree);
                }
            }
        }
        return all_trees;
    }
};