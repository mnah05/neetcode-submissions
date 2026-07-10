class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        for(const auto& e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int res = 0;
        for(int node = 0; node < n; node++) {
            if(!vis[node]){
                dfs(adj,vis,node);
                res++;
            }
        }
        return res;
    }

    void dfs(const vector<vector<int>>& adj,vector<bool>& vis,int node) {
        vis[node] = true;
        for(int nei: adj[node]) {
            if(!vis[nei]) {
                dfs(adj,vis,nei);
            }
        }
    }
};
