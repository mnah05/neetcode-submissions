class Solution {
   public:
    void dfs(int i, int curr, int target, const vector<int>& cand, vector<int>& temp,
             vector<vector<int>>& res) {
        if (curr == target) {
            res.push_back(temp);
            return;
        }

        for (int index = i; index < cand.size(); index++) {
            if (index > i && cand[index] == cand[index - 1]) continue;

            if (curr + cand[index] > target) break;

            temp.push_back(cand[index]);

            dfs(index + 1, curr + cand[index], target, cand, temp, res);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> temp;

        dfs(0, 0, target, candidates, temp, res);

        return res;
    }
};
