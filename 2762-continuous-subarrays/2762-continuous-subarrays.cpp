#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int i = 0, j = 0;
        long long count = 0;
        map<int, int> mp;

        for (i = 0; i < nums.size(); ++i) {
            mp[nums[i]]++;
            int maxi = mp.rbegin()->first;
            int mini = mp.begin()->first;
            cout<<maxi<<" "<<mini<<endl;
            while(j<=i&&maxi - mini > 2) {
                cout<<j<<endl;
                mp[nums[j]]--;  
                if(mp[nums[j]]==0)mp.erase(nums[j]);
                 maxi = mp.rbegin()->first;
                mini = mp.begin()->first;
                j++;
            }
            count += i - j + 1;
        }

        return count;
    }
};
