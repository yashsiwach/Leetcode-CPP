class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long long totalSize = 0; // To keep track of the total size of the decoded string.
        
        // Calculate the total size of the decoded string.
        for (char c : s) {
            if (isdigit(c)) {
                int digit = c - '0';
                totalSize *= digit;
            } else {
                totalSize++;
            }
        }
        
        // Decode the string in reverse order.
        for (int i = s.size() - 1; i >= 0; i--) {
            char currentChar = s[i];
            if (isdigit(currentChar)) {
                int digit = currentChar - '0';
                totalSize /= digit;
                k %= totalSize;
            } else {
                if (k == 0 || k == totalSize) {
                    return string(1, currentChar); // Found the character at k.
                }
                totalSize--; // Decrease the size for a single character.
            }
        }
        
        return ""; // This line should never be reached.
    }
};