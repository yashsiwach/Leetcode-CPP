class Solution {
public:
bool check(int mid,vector<int>&v,int m,int k)
{
    int temp=0,count=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]<=mid)
        {
            count++;
        }
        else
        {
            count=0;
        }
        if(count==k)
        {
            count=0;
            temp++;
        }
    }
    if(temp>=m)return true;
    else return false;

}
    int minDays(vector<int>& b, int m, int k) {
        int ans=0;
        if(m*k>b.size())return -1;
        int l=0,r=1e9;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(check(mid,b,m,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
        
    }
};