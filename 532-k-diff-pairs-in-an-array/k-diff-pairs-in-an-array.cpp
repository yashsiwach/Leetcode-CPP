class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int count=0;
        sort(nums.begin(),nums.end());
        set<pair<int,int>>s;
        for(int i=0;i<nums.size()-1;i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(i!=j&&(abs(nums[i]-nums[j])==k))
                {
                    cout<<i<<" "<<j<<endl;
                    s.insert({nums[i],nums[j]});
                }
            }
        }
        cout<<endl;
        for(auto i:s)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        count=s.size();
        return count;
        
    }
};