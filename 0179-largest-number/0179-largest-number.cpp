class Solution {
public:
    static bool compareStrings(const string &a, const string &b) {
        return a + b > b + a; // Custom comparison to form the largest number
    }

    string largestNumber(vector<int>& nums) {
        string ans;
        vector<string> temp;
        for (auto it : nums) temp.push_back(to_string(it));

        sort(temp.begin(), temp.end(), compareStrings);

        for (auto it : temp) ans += it;

        // Handle the case where the result is all zeros, e.g., [0, 0]
        if (ans[0] == '0') return "0";

        return ans;
    }
};