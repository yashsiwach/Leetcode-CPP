class Solution {
public:
    vector<vector<int>> ans;

    void solve(vector<int>& temp, const vector<int>& original, int i, int n, int k) {
        if (i == n) {
            if (temp.size() == k) {
                ans.push_back(temp);
            }
            return;
        }
        temp.push_back(original[i]);
        solve(temp, original, i + 1, n, k);
        temp.pop_back();
        solve(temp, original, i + 1, n, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> original;
        for (int i = 1; i <= n; i++) {
            original.push_back(i);
        }
        vector<int> temp;
        int i = 0;
        solve(temp, original, i, n, k);
        return ans;
    }
};
