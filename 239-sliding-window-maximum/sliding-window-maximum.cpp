class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>q;
        vector<int>v;
        for(int i=0;i<k;i++)
        {
            while(!q.empty()&& nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
        }
        v.push_back(nums[q.front()]);
        for(int i=k;i<nums.size();i++)
        {
            while(!q.empty()&& q.front()<=i-k)
            {
                q.pop_front();
            }
             while(!q.empty()&& nums[q.back()]<nums[i])
            {
                q.pop_back();
            }
            q.push_back(i);
           
v.push_back(nums[q.front()]);
        }
         
         return v;
        
    }
};