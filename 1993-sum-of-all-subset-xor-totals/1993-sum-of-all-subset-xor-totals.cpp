class Solution {
public:
    void solve(vector<int>&v,int i,int sum,int &ans)
    {
        if(i==v.size())
        {
            ans=ans+sum;
            return ;
        }
        solve(v,i+1,sum^v[i],ans);
        solve(v,i+1,sum,ans);

    }
    int subsetXORSum(vector<int>& nums) {
        int i=0,sum=0;
        int ans=0;
        solve(nums,i,sum,ans);
        return ans;
        
    }
};