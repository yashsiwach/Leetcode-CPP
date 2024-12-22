
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& h, vector<vector<int>>& q) {
        int n = h.size();
        map<int, vector<int>> mp;

      
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (h[j] > h[i])
                    mp[h[i]].push_back(j);
            }
        }
        vector<int> ans;
        for (auto& it : q) {
            int a = it[0];
            int b = it[1];
            if (a > b) swap(a, b);

            if (h[a] < h[b] || a == b) {
                ans.push_back(b);
            } else {
                auto iter = upper_bound(mp[h[a]].begin(), mp[h[a]].end(), b);
                if (iter == mp[h[a]].end()) {
                    ans.push_back(-1);
                } else {
                    ans.push_back(*iter);
                }
            }
        }
        return ans;
    }
};
