class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int ans;
    
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>arr[i+1])
            {
                return i;
            }
        }
        return 0;
        
    }
};