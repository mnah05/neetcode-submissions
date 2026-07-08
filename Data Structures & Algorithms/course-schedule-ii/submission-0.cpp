class Solution {
public:
    unordered_map<int, vector<int>> mpp;
    vector<int> indegree;
    vector<int> ans;

    void bfs(unordered_map<int, vector<int>>& mpp, int n,
             vector<int>& indegree) {
        queue<int> q;
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ans.push_back(i);
                count++;
            }
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int& nei : mpp[u]) {
                indegree[nei]--;

                if (indegree[nei] == 0) {
                    q.push(nei);
                    ans.push_back(nei);
                    count++;
                }
            }
        }

        if (count != n) {
            ans.clear();
        }
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        indegree.resize(numCourses, 0);

        for (auto& adj : prerequisites) {
            int a = adj[0];
            int b = adj[1];

            mpp[b].push_back(a);
            indegree[a]++;
        }

        bfs(mpp, numCourses, indegree);

        return ans;
    }
};