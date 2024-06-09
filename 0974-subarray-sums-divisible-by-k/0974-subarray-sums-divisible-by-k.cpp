class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>v(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)v[i]=nums[i];
            else v[i]=v[i-1]+nums[i];
        }
        int ans=0;
        map<int,int>mp={{0,1}};
        for(int i=0;i<n;i++)
        {
            v[i]=(v[i]%k+k)%k;
            cout<<v[i]<<" ";
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
           
            if(mp.find(v[i])!=mp.end())
            {
                ans+=mp[v[i]];
            }
            mp[v[i]]++;
            
        }
        
        return ans;
        
    }
};