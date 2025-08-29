class Solution {
public:
    int titleToNumber(string& s) {
        int ans = 0;
        int pwr = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            int v = s[i] - 'A' + 1;
            ans += v * pow(26, pwr);
            pwr++;
        }
        return ans;
    }
};