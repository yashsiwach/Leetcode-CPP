class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<long long>pref(nums.size());
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
            {
                pref[i]=nums[i];
            }
            else
            {
                pref[i]=pref[i-1]+nums[i];
            }
        }
        long long count=0,maxi=0;
        for(int i=2;i<pref.size();i++)
        {
            if(pref[i-1]>nums[i])
            {
                maxi=max(pref[i],maxi);
            }
        }
        return maxi==0?-1:maxi;
        
        
    }
};