class Solution {
    private:
    void dfs(unordered_map<int ,bool>&vls,int src,vector<vector<int>>&isconnected)
    {
        vls[src]=true;
        int size=isconnected[src].size();
        for(int col=0;col<size;col++)
        {
            if(isconnected[src][col]==1)
            {
                if(!vls[col])
                {
                    dfs(vls,col,isconnected);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int ,bool > visited;
        int count=0;
        int n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                dfs(visited ,i ,isConnected);
                count++;
            }
        }return count;
    }
};