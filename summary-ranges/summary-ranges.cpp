class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>jat;
        if(nums.size()==0) return jat;
        long long start=0,end=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            
            if((nums[i]+1)==nums[i+1])
            {
                end++;
            }
            else
            {
                if(start==end)
                jat.push_back(to_string(nums[start]));
                else
                {
                    string s=to_string(nums[start]);
                    string e=to_string(nums[end]);
                    string final=s+"->"+e;
                    jat.push_back(final);
                }
                start=end+1;
                end+=1;
            }
        }
        if(start==end)
                jat.push_back(to_string(nums[start]));
                else
                {
                    string s=to_string(nums[start]);
                    string e=to_string(nums[end]);
                    string final=s+"->"+e;
                    jat.push_back(final);
                }

        return jat;
        
    }
};