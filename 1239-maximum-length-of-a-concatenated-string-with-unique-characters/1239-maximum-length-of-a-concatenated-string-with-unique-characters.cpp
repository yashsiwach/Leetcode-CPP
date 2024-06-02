#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int solve(vector<string>& v, int ind, string& s) {
        if (ind == v.size()) {
            return s.size();
        }
        
        string temp = s;
        s += v[ind];
        
        // Check if the new string s contains all unique characters
        set<char> st(s.begin(), s.end());
        int take = 0, skip = 0;
        if (st.size() == s.size()) {
            take = solve(v, ind + 1, s);
        }
        
        s = temp; // Backtrack
        skip = solve(v, ind + 1, s);
        
        return max(take, skip);
    }
    
    int maxLength(vector<string>& arr) {
        string s;
        return solve(arr, 0, s);
    }
};
