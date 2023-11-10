     
class Solution {
public:
    
    void helper(vector<bool>& visited, vector<int>& v, vector<vector<int>>& ans, vector<int>& nums)
    {
        if(v.size() == nums.size())
        {
            ans.push_back(v);
            return;
        }
        
        
        for(int ind = 0; ind < nums.size(); ind++)
        {
            if(visited[ind] == true|| (ind > 0 && nums[ind] == nums[ind - 1] && visited[ind - 1] == false))
                continue;
            
            visited[ind] = true;
            v.push_back(nums[ind]);
            helper(visited, v, ans, nums);
            v.pop_back();
            visited[ind] = false;
        }
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<bool> visited(n, false);
        vector<vector<int>> ans;
        vector<int> v;
        helper(visited, v, ans, nums);
        return ans;
    }
}; 