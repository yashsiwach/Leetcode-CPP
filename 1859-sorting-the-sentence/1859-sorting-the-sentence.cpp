class Solution {
public:
    string sortSentence(std::string s) {
        int i = 0, j = 0, count = 0;
        for (auto it : s) {
            if (isspace(it)) {
                count++;
            }
        }

        vector<string> v(count + 1);
        while (j < s.length()) {
            if (isdigit(s[j]) || j == s.length()-1 ) {
                string temp = s.substr(i, j - i);
              
                v[s[j]-'1'] = temp;
                i = j + 2;
            }
            j++;
          
        }
        for (auto it : v) {
            cout << it << " ";
        }
        string st;
        for(auto it:v)
        {
            st+=it;
            st+=' ';
        }
        st.pop_back();
        return st;
    }
};