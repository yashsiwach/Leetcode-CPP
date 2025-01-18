class Solution {
public:
    long long mod = 1e9 + 7;

    long long lcm(long long a, long long b) {
        return (a / __gcd(a, b)) * b;
    }

    long long check(long long a, long long b, long long n) {
        return (n / a + n / b - n / lcm(a, b));
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, h = 1e18, ans = 0;

        while (l <= h) {
            long long mid = l + (h - l) / 2;
            long long count = check(a, b, mid);

            if (count >= n) {
                ans = mid; // Store potential result
                h = mid - 1; // Narrow the search
            } else {
                l = mid + 1;
            }
        }

        return ans % mod;
    }
};
