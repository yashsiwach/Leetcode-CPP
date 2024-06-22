#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int>v(nums.begin(),nums.end());
        int operations = 0;
        bool flipped = false;  

        for (int i = 0; i < nums.size(); ++i) {
          
            int currentValue = flipped ? 1 - nums[i] : nums[i];
            
            if (currentValue == 0) {
                ++operations;
                flipped = !flipped; 
            }
        }
     

        return operations;
    }
};
