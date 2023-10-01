class Solution {
public:
    string reverseWords(string s) {
        int temp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isspace(s[i])) {
                reverse(s.begin() + temp, s.begin() + i);
                temp = i + 1; 
            }
        }
        
        
        reverse(s.begin() + temp, s.end());
        
        return s;
    }
};
