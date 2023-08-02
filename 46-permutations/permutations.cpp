class Solution {
public:
    void solve(vector<int>&nums,vector<int>temp,map<int,int>&i,vector<vector<int>>&ans)
    {
        if(temp.size()==nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        for(int j=0;j<nums.size();j++)
        {
            if(i[j]!=1){
            temp.push_back(nums[j]);
            i[j]=1;
            solve(nums,temp,i,ans);
            i[j]=0;
            temp.pop_back();
        }
        }
        

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int>>ans;
        map<int,int>i;
        solve(nums,temp,i,ans);
        return ans;

        
    }
};