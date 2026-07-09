class Solution {
   public:
    bool dfs(int node, int par, const vector<vector<int>>& adj, unordered_set<int>& visit) {
        if (visit.count(node)) return false;

        visit.insert(node);

        for (int nei : adj[node]) {
            if (nei == par) continue;

            if (!dfs(nei, node, adj, visit)) return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visit;

        if (!dfs(0, -1, adj, visit)) return false;

        return visit.size() == n;
    }
};