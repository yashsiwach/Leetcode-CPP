class Solution {
public:
    bool search(vector<int>& nums, int target) {
        for(auto i:nums)
        {
            if(target==i)
            {
                return true;
            }
        }
        return false;
        
    }
};