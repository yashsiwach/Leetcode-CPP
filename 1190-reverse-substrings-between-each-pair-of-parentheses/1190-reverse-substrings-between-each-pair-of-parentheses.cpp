class Solution {
public:
    string reverseParentheses(string s) {
        string str;
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')') {
                while (!st.empty()) {
                    if (st.top() == "(") {
                        st.pop();
                        if(str.length()>0)st.push(str);
                        str.clear();
                        break;
                    } else {
                        string temp=st.top();
                        if(temp.length()>1)reverse(temp.begin(),temp.end());
                        str = str+temp;
                        st.pop();
                    }
                }
            } else {
                st.push(string(1, s[i])); 
            }
        }
        
   
        string result;
        while (!st.empty()) {
            result = st.top() + result;
            st.pop();
        }

        return result;
    
        
    }
};