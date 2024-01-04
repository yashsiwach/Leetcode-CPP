class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it:nums)mp[it]++;
        int count=0;
        for(auto it:mp)
        {
            if(it.second==1)return -1;
            if(it.second%3==0)
            {
                count+=it.second/3;
            }
            else
            {
                count+=it.second/3;
                count++;
            }
        }
        return count;
    }
};