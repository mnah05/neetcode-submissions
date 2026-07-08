class Solution {
   public:
    unordered_map<int, vector<int>> mpp;
    unordered_set<int> vis;
    bool dfs(int crs) {
        if (vis.count(crs)) {
            return false;
        }
        if (mpp[crs].empty()) {
            return true;
        }
        vis.insert(crs);
        for (int c : mpp[crs]) {
            if (!dfs(c)) {
                return false;
            }
        }
        vis.erase(crs);
        mpp[crs].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            mpp[i] = {};
        }

        for (const auto& req : prerequisites) {
            mpp[req[0]].push_back(req[1]);
        }
        for (int c = 0; c < numCourses; c++) {
            if (!dfs(c)) {
                return false;
            }
        }
        return true;
    }
};
