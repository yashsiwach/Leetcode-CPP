#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Adjacency list representation of the graph
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0], v = edges[i][1];
            double prob = succProb[i];
            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // Max-heap to store the current node and the probability to reach it
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});

        // Vector to store the maximum probability to reach each node
        vector<double> maxProb(n, 0.0);
        maxProb[start_node] = 1.0;

        while (!pq.empty()) {
            auto [currProb, node] = pq.top();
            pq.pop();

            if (node == end_node) return currProb;

            for (auto& [neighbor, edgeProb] : adj[node]) {
                double newProb = currProb * edgeProb;
                if (newProb > maxProb[neighbor]) {
                    maxProb[neighbor] = newProb;
                    pq.push({newProb, neighbor});
                }
            }
        }

        return 0.0; // If there's no path from start_node to end_node
    }
};
