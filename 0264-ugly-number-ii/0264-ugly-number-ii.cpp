class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans(n + 1, 0);
        ans[1] = 1;  // The first ugly number is 1.

        int i2 = 1, i3 = 1, i5 = 1;
        for (int i = 2; i <= n; i++) {
            long long next2 = ans[i2] * 2;
            long long next3 = ans[i3] * 3;
            long long next5 = ans[i5] * 5;
            
            ans[i] = min(next2, min(next3, next5));

            // Advance the indices for whichever factor was used
            if (ans[i] == next2) i2++;
            if (ans[i] == next3) i3++;
            if (ans[i] == next5) i5++;
        }

        return ans[n];
    }
};
