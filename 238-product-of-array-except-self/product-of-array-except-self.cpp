class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //creating prefix sum 
        int n=nums.size();
        vector<int>prefix(n,0);
        for(int i=0;i<n;i++ )
        {
            if(i==0){
                prefix[i]=nums[i];
            }
            else
            {
                prefix[i]=prefix[i-1]*nums[i];
            }
        }
        vector<int>prefix2(n,0);
        for(int i=n-1;i>=0;i-- )
        {
            if(i==n-1){
                prefix2[i]=nums[i];
            }
            else
            {
                prefix2[i]=prefix2[i+1]*nums[i];
            }
        }
        vector<int>ans(n,0);

        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                ans[i]=prefix2[i+1];
            }
            else if(i==n-1)
            {
                ans[i]=prefix[i-1];
            }
            else
            {
                ans[i]=prefix[i-1]*prefix2[i+1];
            }
        }
        return ans;
      
    }
};