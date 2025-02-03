class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>dpf(n,1),dpb(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dpf[i]=max(dpf[i],dpf[j]+1);
                }
            }
        }
        reverse(nums.begin(),nums.end());
          for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    dpb[i]=max(dpb[i],dpb[j]+1);
                }
            }
        }
        reverse(dpb.begin(),dpb.end());
        // for(auto it:dpf)cout<<it<<" ";
        // cout<<endl;
        // for(auto it:dpb)cout<<it<<" ";
        // cout<<endl;
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(dpf[i]>1&&dpb[i]>1){
            int re=n-(dpf[i]+dpb[i]-1);
            ans=min(ans,re);
            }
        }
        return ans;

    }
};