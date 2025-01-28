class Solution {
public:
    bool rec(string a, string b, string c, int i, int j, int k) {
        if(k == c.size()) {
            return i == a.size() && j == b.size();
        }
        
        bool e = false;
        bool f = false;
        
        if(i < a.size() && a[i] == c[k]) {
            e = rec(a, b, c, i + 1, j, k + 1);
        }
        
        if(j < b.size() && b[j] == c[k]) {
            f = rec(a, b, c, i, j + 1, k + 1);
        }
        
        return e || f;
    }
    
    bool isInterleave(string a, string b, string c) {
        return rec(a, b, c, 0, 0, 0);
    }
};
