class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count=0;
        int l=grid.size();
       
        for(int i=0;i<l;i++)
        {   int b=grid[i].size();
            for(int j=0;j<b;j++)
            {
                if(grid[i][j]<0)
                {
                    count++;
                }
            }
        }return count;
        
    }
};