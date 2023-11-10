class Solution {
public:

    void solve(int u, int prev, unordered_map<int, vector<int>> &adj, vector<int> &ans){
        ans.push_back(u);

        for(int &v : adj[u]){
            if(v != prev){
                solve(v, u, adj, ans);
            }
        }
    }

    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> adj;
        vector<int> ans;
        for(vector<int> & vec : adjacentPairs){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int start = -1;

        //check for that one element whose neighbour is only one
        for(auto &it : adj){
            if(it.second.size() == 1){
                start = it.first;
                break;
            }
        }

        solve(start, -1, adj, ans);

        return ans;
    }
};