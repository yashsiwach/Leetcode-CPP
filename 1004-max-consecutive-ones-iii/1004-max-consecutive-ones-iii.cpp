class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j=0,maxi=0,count=0;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
            maxi=max(maxi,mp[1]);
            while((i-j+1)-maxi>k)
            {
                mp[nums[j]]--;
                j++;
            }
            count=max(count,i-j+1);
        }
        return count;
    }
};