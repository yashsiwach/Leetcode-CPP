class Solution {
public:
    bool dfs(vector<vector<bool>>& visi, vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j) {
        // Check bounds and if the cell is water or already visited in grid2
        if (i < 0 || i >= grid1.size() || j < 0 || j >= grid1[0].size() || grid2[i][j] == 0 || visi[i][j]) 
            return true;
        
        // Mark this cell as visited
        visi[i][j] = true;

        // If grid1 has water where grid2 has land, it's not a sub-island
        bool isSubIsland = grid1[i][j] == 1;

        // Explore all four directions
        isSubIsland &= dfs(visi, grid1, grid2, i + 1, j);  // Down
        isSubIsland &= dfs(visi, grid1, grid2, i - 1, j);  // Up
        isSubIsland &= dfs(visi, grid1, grid2, i, j + 1);  // Right
        isSubIsland &= dfs(visi, grid1, grid2, i, j - 1);  // Left

        return isSubIsland;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;

        vector<vector<bool>> visi(n, vector<bool>(m, false));

        // Iterate through each cell in grid2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Start DFS if the cell is land in grid2 and hasn't been visited
                if (grid2[i][j] == 1 && !visi[i][j]) {
                    if (dfs(visi, grid1, grid2, i, j)) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
