class Solution {
public:
    int numSteps(string s) {
        reverse(s.begin(), s.end());
        int count = 0;

        while (s.size() != 1) {
            if (s[0] == '0') {
                // If the least significant bit is '0', divide by 2 by erasing it
                s.erase(s.begin());
            } else {
                // If the least significant bit is '1', add 1 to the binary number
                int flag = 0;
                for (int i = 0; i < s.size(); ++i) {
                    if (s[i] == '0') {
                        s[i] = '1';
                        flag = 1;
                        break;
                    } else {
                        s[i] = '0';
                    }
                }
                // If the entire string was '1's, we need to add a '1' at the end
                if (flag == 0) {
                    s.push_back('1');
                }
            }
            count++;
        }

        return count;
    }
};
