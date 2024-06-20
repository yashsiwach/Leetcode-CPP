class Solution {
public:
    bool check(vector<int>& v, int m, int mid) {
        int i = 0, count = 1;  // Start by placing the first ball
        for (int j = 1; j < v.size(); ++j) {
            if (v[j] - v[i] >= mid) {
                count++;
                i = j;  // Place the ball at v[j]
                if (count == m) return true;
            }
        }
        return false;
    }

    int maxDistance(vector<int>& p, int m) {
        int ans = 0;
        sort(p.begin(), p.end());
        int l = 1, r = p.back() - p.front();  // More appropriate bounds
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(p, m, mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
