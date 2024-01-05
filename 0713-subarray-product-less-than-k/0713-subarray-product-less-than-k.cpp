class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            int i=0,j=0,count=0,p=1;
            for(int i=0;i<nums.size();i++)
            {
                p=p*nums[i];
                while(j<=i&&p>=k)
                {
                    p/=nums[j];
                    j++;
                }
                count+=(i-j)+1;
            }   
            return count;
    }
};