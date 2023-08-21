class Solution {
public:
// void solve(int ind,vector<string>&v,string &s,string temp)
// {
//     if(ind>=s.size())
//     {
//         v.push_back(temp);
//         return;
//     }
//     temp+=s[ind];
//     solve(ind+1,v,s,temp);
//     temp.pop_back();
//     solve(ind +1,v,s,temp);
//  }
    bool repeatedSubstringPattern(string s) {
    int ori = s.size();

    for (int len = 1; len <= ori / 2; len++) {
        if (ori % len == 0) {
            int div = ori / len;
            string sub = s.substr(0, len);
            string formed = "";

            for (int j = 0; j < div; j++) {
                formed += sub;
            }

            if (formed == s) {
                return true;
            }
        }
    }

    return false;


    }
};