class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> ans;
        int ans1;
        for(auto it:nums) ans[it]++;
        int len=nums.size()/2;
        for(auto i:ans)
        {
            if(i.second>len) ans1=i.first;

        }return ans1;
    }
};