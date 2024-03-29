class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long count=0;
        unordered_map<int,int>mp;
        int i=0,j=0;
        int n=nums.size();
        int x=*max_element(nums.begin(),nums.end());
        while(j<nums.size())
        {
            mp[nums[j]]++;
            while(mp[x]>=k)
            {
                count+=(n-j);
                mp[nums[i]]--;
                i++;
            }
            j++;
        }
        return count;
    }
};