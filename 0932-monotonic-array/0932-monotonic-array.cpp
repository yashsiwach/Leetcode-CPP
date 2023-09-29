class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int>inc;
        vector<int>dec;
        set<int>st(nums.begin(),nums.end());
        if(st.size()==1)return true;
        bool ans,ans2;
        inc=nums;
        sort(inc.begin(),inc.end());
        dec=inc;
        reverse(dec.begin(),dec.end());
        if(nums==inc)
        {
            ans=true;
        }
        else ans=false;
        if(nums==dec)
        {
            ans2=true;
        }
        else ans2=false;
        if(ans^ans2)
        {
            return true;
        }
        else return false;
        
    }
};