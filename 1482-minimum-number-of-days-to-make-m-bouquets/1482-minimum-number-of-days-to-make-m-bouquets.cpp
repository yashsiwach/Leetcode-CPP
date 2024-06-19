class Solution {
public:
    bool check(int mid, vector<int>& v, int m, int k) {
        int temp = 0, count = 0;
        for(int i = 0; i < v.size(); i++) {
            if(v[i] <= mid) {
                count++;
            } else {
                count = 0;
            }
            if(count == k) {
                count = 0;
                temp++;
            }
        }
        return temp >= m;
    }

    int minDays(vector<int>& b, int m, int k) {
        long long n = b.size();
        long long required = (long long)m * k;  // Avoid overflow by using long long

        // If it's impossible to make m bouquets
        if(required > n) return -1;

        int l = 0, r = 1e9, ans = 0;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(check(mid, b, m, k)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
