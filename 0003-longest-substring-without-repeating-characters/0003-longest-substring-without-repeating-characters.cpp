class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char>st;
        int l=0,maxi=0,n=s.size();
        for(int i=0;i<n;i++){
        
            while(st.count(s[i])){
                st.erase(s[l]);l++;
            }
            st.insert(s[i]);
            maxi=max(maxi,(i-l+1));
        }
        return maxi;
    }
};