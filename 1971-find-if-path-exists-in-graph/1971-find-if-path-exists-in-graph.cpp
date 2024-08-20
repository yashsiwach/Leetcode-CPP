class Solution {
public:
    void dfs(vector<bool>& visi, vector<vector<int>>& adj, int s) {
        visi[s] = true;
        for (auto it : adj[s]) {
            if (!visi[it]) dfs(visi, adj, it);
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<bool> visi(n, false);
        dfs(visi, adj, s);

        return visi[d];
    }
};
