class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // vector<int>temp;
        // int len=nums.size();
        // int j=0;
        // k=k%len;
        // for(int i=0;i<abs(len-k);i++)
        // {
        //     //1,2,3,4
        //     cout<<nums[i]<<" ";
        //     temp.push_back(nums[i]);
        // }
        // cout<<endl;
        // for(int i=abs(len-k);i<len;i++)
        // {
        //     //5,6,7

        //     cout<<nums[i]<<endl;
        //     nums[abs(i-abs(len-k))]=nums[i];
        // }
        // for(int i=k;i<len;i++)
        // {
        //     nums[i]=temp[j];
        //     j++;
        // }
        
        k=k%nums.size();
        reverse(nums.begin(),nums.begin()+(nums.size()-k));

        reverse(nums.begin()+(nums.size()-k),nums.end());
    
        reverse(nums.begin(),nums.end());
            

        
        

        
        
    }
};