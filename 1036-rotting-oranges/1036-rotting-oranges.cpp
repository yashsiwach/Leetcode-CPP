class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timer=0;
        queue<pair<pair<int,int>,int>>q;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visi(n,vector<bool>(m,false));
        vector<int>v1={-1,0,1,0};
        vector<int>v2={0,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    visi[i][j]=true;
                    q.push({{i,j},timer});
                }
            }
        }
        while(!q.empty())
        {
            int row=q.front().first.first;
            int col=q.front().first.second;
            int sec=q.front().second;
            q.pop();

            for(int i=0;i<4;i++)
            {
                timer=max(sec,timer);
                int nrow=row+v1[i];
                int ncol=col+v2[i];
                if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1&&!visi[nrow][ncol])
                {
                    q.push({{nrow,ncol},sec+1});
                    visi[nrow][ncol]=true;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1&&!visi[i][j])return -1;
            }
        }
        return timer;
    }
};