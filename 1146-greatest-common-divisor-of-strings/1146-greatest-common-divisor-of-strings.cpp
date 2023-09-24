class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return ""; // If the concatenation doesn't match in both orders, there's no common divisor.
        }

        // Find the GCD of the lengths of the two strings.
        int gcd_len = gcd(str1.length(), str2.length());

        // Extract the common divisor substring from either of the strings.
        return str1.substr(0, gcd_len);
    }
};
