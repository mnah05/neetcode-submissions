class Solution {
   public:
    bool dfs(unordered_map<int, vector<int>>& mpp, int st, int e, vector<bool>& vis) {
        vis[st] = true;

        if (st == e) return true;

        for (int nei : mpp[st]) {
            if (!vis[nei]) {
                if (dfs(mpp, nei, e, vis)) return true;
            }
        }

        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> mpp;

        for (const auto& node : prerequisites) {
            mpp[node[0]].push_back(node[1]);
        }

        vector<bool> ans;

        for (const auto& q : queries) {
            vector<bool> vis(numCourses, false);
            ans.push_back(dfs(mpp, q[0], q[1], vis));
        }

        return ans;
    }
};