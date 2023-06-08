class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // int count=0;
        // int l=grid.size();
       
        // for(int i=0;i<l;i++)
        // {   int b=grid[i].size();
        //     for(int j=0;j<b;j++)
        //     {
        //         if(grid[i][j]<0)
        //         {
        //             count++;
        //         }
        //     }
        // }return count;
        int n=grid.size(), m=grid[0].size(),r=n-1,c=0,count=0;
        while(r>=0&&c<m)
        {
            if(grid[r][c]<0) 
            {
                --r;
                count+=m-c;
            }
            else
                ++c;

        }return count;
    }
};