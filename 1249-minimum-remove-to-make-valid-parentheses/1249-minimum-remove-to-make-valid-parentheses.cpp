#include <string>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (!st.empty()) {
                    st.pop();
                } else {
                    s[i] = '*'; // Marking ')' for removal
                }
            }
        }

        while (!st.empty()) {
            s[st.top()] = '*'; // Marking '(' for removal
            st.pop();
        }

        for (char c : s) {
            if (c != '*') {
                ans += c;
            }
        }

        return ans;
    }
};
