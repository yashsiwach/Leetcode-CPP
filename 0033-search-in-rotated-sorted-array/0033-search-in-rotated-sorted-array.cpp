class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e)
        {
            if(nums[s]==target)
            {
                return s;
            }
            else if(nums[e]==target)
            {
                return e;
            }
            else if(nums[s]<target)
            {
                s++;
            }
            else
            {
                e--;
            }
        }return -1;
        
    }
};