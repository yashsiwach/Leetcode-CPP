class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int last = target[target.size() - 1]; // Corrected the last index to use target.size()
        
        for (int i = 1; i <= last; i++) {
            if (binary_search(target.begin(), target.end(), i)) {
                ans.push_back("Push");
            } else {
                ans.push_back("Push");
                ans.push_back("Pop"); // Only push "Pop" when the element is not found in 'target'
            }
        }
        return ans;
    }
};
