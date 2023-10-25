class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                break;
            }
            else if(nums[i]+nums[j]>target)
            {
                j--;
            }
            else if(nums[i]+nums[j]<target)
            {
                i++;
            }
        }
        return v;
    }
};