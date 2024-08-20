#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // Depth-First Search to count nodes in a component
    int dfs(vector<bool>& visi, unordered_map<int, vector<int>>& mp, int s) {
        int count = 1;
        visi[s] = true;
        for (auto it : mp[s]) {
            if (!visi[it]) {
                count += dfs(visi, mp, it);
            }
        }
        return count;
    }

    // Breadth-First Search to verify if the component is a complete graph
    bool bfs(int size, vector<bool>& visi, unordered_map<int, vector<int>>& mp, int s) {
        queue<int> q;
        q.push(s);
        visi[s] = true;
        int edgeCount = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            int neighbors = mp[node].size();
            
            // Count edges in the component
            edgeCount += neighbors;
            
            if (neighbors != size - 1) return false;
            
            for (auto& it : mp[node]) {
                if (!visi[it]) {
                    visi[it] = true;
                    q.push(it);
                }
            }
        }
        
    
        return true;
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> mp;
        for (auto it : edges) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }
        
        vector<bool> visi(n, false), visi2(n, false);
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (!visi2[i]) {
                int componentSize = dfs(visi2, mp, i);
                if (!visi[i]) {
                    if (bfs(componentSize, visi, mp, i)) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
