class Solution {
public:
vector<vector<int>>ans;
    void solve(int index,vector<int>&candidates,int target,vector<int>temp)
    {
        if(index==candidates.size())
        {
            if(target==0)
            {
                ans.push_back(temp);
            

            }
            return;
            
        }
        if(candidates[index]<=target){
        temp.push_back(candidates[index]);
        solve(index,candidates,target-candidates[index],temp);
        temp.pop_back();
        }
        solve(index+1,candidates,target,temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index=0;
        vector<int>temp;
         solve(index,candidates,target,temp);
         return ans;
        
    }
};