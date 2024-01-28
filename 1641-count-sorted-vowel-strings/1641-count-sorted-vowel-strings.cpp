

class Solution {
public:
    int solve(int n, string s, string& str) {
        if (str.size() == n) {
            return 1;
        }
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (str.empty() || s[i] >= str.back()) {
                str.push_back(s[i]);
                count += solve(n, s, str);
                str.pop_back(); // Backtrack to restore previous state
            }
        }
        return count;
    }

    int countVowelStrings(int n) {
        string s = "aeiou";
        string str;
        int ans = solve(n, s, str);
        return ans;
    }
};
