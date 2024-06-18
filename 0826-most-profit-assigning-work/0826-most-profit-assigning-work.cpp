class Solution {
public:
    int maxProfitAssignment(vector<int>& d, vector<int>& p, vector<int>& w) {
        vector<pair<int, int>> v;
        for(int i = 0; i < p.size(); i++) {
            v.push_back({d[i], p[i]});
        }

        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            if(a.first != b.first) return a.first < b.first;
            else return a.second < b.second;
        });

        vector<int> pref(p.size());
        for(int i = 0; i < v.size(); i++) {
            if(i == 0) pref[i] = v[i].second;
            else pref[i] = max(pref[i - 1], v[i].second);
        }

        int ans = 0;
        for(auto &it : w) {
            auto temp = upper_bound(v.begin(), v.end(), make_pair(it, INT_MAX), [](const auto &a, const auto &b) {
                return a.first < b.first;
            });

            if (temp != v.begin()) {
                --temp;
                int ind = temp - v.begin();
                ans += pref[ind];
            }
        }

        return ans;
    }
};
