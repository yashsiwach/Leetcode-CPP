class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>v;
        map<int,int>mp;
        int i=0,j=0;
        while(j<nums.size())
        {
            mp[nums[j]]++;
            if((j-i)+1<k)
            {
                j++;
            }
            else
            {
                int maxi=mp.rbegin()->first;
                cout<<maxi<<endl;
                
                mp[nums[i]]--;
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                v.push_back(maxi);
                i++;
                j++;
            }
            
        }
        return v;
    }
};