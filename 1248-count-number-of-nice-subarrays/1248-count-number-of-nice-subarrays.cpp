class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int count=0,ans=0,temp=0,j=0,l=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2!=0)count++;
            if(count==k)
            {
                while(count==k)
                {
                    if(nums[j]%2!=0)
                    {
                        count--;
                    }
                    j++;
                }
                
                l=j-1;
                l--;
                while(l>=0&&nums[l]%2==0)
                {
                    l--;
                    
                }
                temp=i;
                temp++;
                while(temp<nums.size()&&nums[temp]%2==0)
                {
                    temp++;
                }
               
               int one=(j-1)-l;
               int two=(temp-i);
               int ok=0;
                if(min(one,two)==0)ok=max(one,two);
                else ok=one*two;
                 cout<<ok<<" "<<j<<" "<<l<<" "<<temp<<" "<<i<<endl;
                ans+=ok;
            }
            
        }
        return ans;
    }
};