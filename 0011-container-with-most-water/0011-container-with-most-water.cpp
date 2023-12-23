class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0,j=height.size()-1;
        int count=0,maxi=0;
        while(i<j)
        {
            count=min(height[i],height[j])*(j-i);
            maxi=max(count,maxi);
            if(height[i]<height[j])
            {
                i++;

            }
            else j--;
            
            
        }
        return maxi;
    }
};