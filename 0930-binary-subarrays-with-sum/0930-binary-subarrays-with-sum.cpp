class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int count=0;
      unordered_map<int,int> mp;
      mp[0]=1;
      int pre_sum=0;
      for(auto i:nums)
      {
          pre_sum+=i;
          int remove=pre_sum-goal;
          if(mp.count(remove)!=0)
          {
              count+=mp[remove];
          }
          mp[pre_sum]++;
      }
      return count;
    }
};