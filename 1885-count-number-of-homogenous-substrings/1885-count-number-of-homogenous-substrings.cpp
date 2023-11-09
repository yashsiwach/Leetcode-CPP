
class Solution {
public:
    int countHomogenous(std::string s) {
        int m = 1000000007;
        int prev = 1;
        int sum = 1;
        for (int i = 1; i < s.length(); i++) {
            int curr = 1;
            if (s[i - 1] == s[i]) {
                curr = (curr + prev) % m;
            }
            sum = (sum + curr) % m;
            prev = curr;
        }
        return sum;
    }
};