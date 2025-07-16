class Solution {
public:

    int orangesRotting(vector<vector<int>>& v) {
        int n=v.size();
        int m=v[0].size();
        vector<int>x={0,-1,0,1};
        vector<int>y={-1,0,1,0};
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            bool ok = false;
            for(int i=0;i<sz;i++){
                auto f=q.front();
                q.pop();
                int cx=f.first;
                int cy=f.second;
                for(int i=0;i<4;i++){
                    int nx=cx+x[i];
                    int ny=cy+y[i];
                    if(nx<0 || ny<0 || nx>=n || ny>=m || v[nx][ny]!=1) continue;
                    v[nx][ny]=2;
                    q.push({nx,ny});
                    ok = true;
                }
            }
            if(ok) ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
