class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        int i=0;
        while(i<s.length())
        {
            if(!st.empty()&&st.top()!=s[i]&&tolower(st.top())==tolower(s[i])){
                st.pop();
            }
            else st.push(s[i]);
            i++;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};