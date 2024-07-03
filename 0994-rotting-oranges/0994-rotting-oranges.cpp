#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& v) {
        queue<pair<int, pair<int, int>>> q;
        int maxi = 0;
        int n = v.size();
        int m = v[0].size(); // Number of columns
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 2) {
                    q.push({i, {j, 0}});
                }
            }
        }

        vector<int> a = {-1, 0, 1, 0};
        vector<int> b = {0, 1, 0, -1};

        while (!q.empty()) {
            pair<int, pair<int, int>> temp = q.front();
            q.pop();
            int i = temp.first;
            int j = temp.second.first;
            int num = temp.second.second;
            for (int k = 0; k < 4; k++) { // Use a different variable name here
                int row = i + a[k]; // Corrected indexing
                int col = j + b[k];
                if (row >= 0 && row < n && col >= 0 && col < m && v[row][col] == 1) {
                    v[row][col] = 2;
                    q.push({row, {col, num + 1}});
                    maxi = max(num + 1, maxi);
                }
            }
        }

        // Check if any fresh orange is left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 1) {
                    return -1;
                }
            }
        }

        return maxi;
    }
};
