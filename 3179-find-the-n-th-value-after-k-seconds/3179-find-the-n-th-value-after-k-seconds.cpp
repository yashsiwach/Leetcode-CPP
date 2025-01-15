class Solution {
public:
int MOD=1e9+7;
    int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res =(res* i)%MOD;
    for (int i = 2; i <= k; ++i)
        res =res/ i;
    return res;
}
    int valueAfterKSeconds(int n, int k) {
        return C(n+k-1,n-1)%MOD;
    }
};