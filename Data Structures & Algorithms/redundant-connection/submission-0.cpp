#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    vector<vector<int>> adj;
    vector<bool> vis;
    unordered_set<int> cycleNodes;
    int cycleStart;

    bool dfs(int node, int par) {
        if (vis[node]) {
            cycleStart = node;
            return true;
        }
        vis[node] = true;
        for (int nei : adj[node]) {
            if (nei == par) continue;
            if (dfs(nei, node)) {
                if (cycleStart != -1) {
                    cycleNodes.insert(node);
                }
                if (node == cycleStart) {
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }

   public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        for (const auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vis.resize(n + 1, false);
        cycleStart = -1;
        dfs(1, -1);
        
        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycleNodes.count(u) && cycleNodes.count(v)) {
                return {u, v};
            }
        }
        return {};
    }
};