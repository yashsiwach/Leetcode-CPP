#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long n=nums.size();
        vector<pair<long long,bool>> left(n), right(n);

        // build prefix (strictly increasing check)
        for (long long i=0;i<n;i++) {
            if (i==0) {
                left[i].first = nums[0];
                left[i].second = true;
            } else {
                left[i].first = left[i-1].first + nums[i];
                left[i].second = (left[i-1].second && nums[i-1] < nums[i]);
            }
        }

        // build suffix (strictly decreasing check)
        for (long long i=n-1;i>=0;i--) {
            if (i==n-1) {
                right[i].first = nums[i];
                right[i].second = true;
            } else {
                right[i].first = right[i+1].first + nums[i];
                right[i].second = (right[i+1].second && nums[i] > nums[i+1]);
            }
        }

        long long ans = LLONG_MAX;
        bool ok = false;

        // try all split points
        for (int i=0;i<n-1;i++) {
            if (left[i].second && right[i+1].second) {
                long long diff = abs(left[i].first - right[i+1].first);
                ans = min(ans, diff);
                ok = true;
            }
        }

        return ok ? ans : -1;
    }
};
