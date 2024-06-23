class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        map<int,int>mp;int j=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            int maxi=(*mp.rbegin()).first;
            int mini=(*mp.begin()).first;
            while(j<nums.size()&&maxi-mini>limit)
            {
                mp[nums[j]]--;
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                j++;
                maxi=(*mp.rbegin()).first;
                mini=(*mp.begin()).first;
            }
            if(maxi-mini<=limit)
            {
                ans=max(ans,i-j+1);
            }
        }
        return ans;
    }
};