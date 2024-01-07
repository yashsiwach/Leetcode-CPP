class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        int i=0,j=0,maxi=0,sum=0;
        while(j<arr.size())
        {
            sum+=arr[j];
            if(j-i+1==k)
            {
                int avg=sum/k;
                if(avg>=t)maxi++;
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return maxi;
        
    }
};