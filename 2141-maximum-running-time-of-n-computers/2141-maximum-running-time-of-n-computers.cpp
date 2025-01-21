
class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long l = 0, h = 1e14, ans = 0;
     
        
        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long tot = 0;
            
        
            for (auto& b : batteries) {
                tot += min((long long)b, mid);
            }
            
            if (tot >= mid * n) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        
        return ans;
    }
};
