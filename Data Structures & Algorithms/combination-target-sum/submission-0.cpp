class Solution {
   public:
    void dfs(int i, const vector<int>& nums, int t, vector<int>& temp, vector<vector<int>>& res) {
        if (t < 0) return;

        if (i >= nums.size()) {
            if (t == 0) res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        dfs(i, nums, t - nums[i], temp, res);
        temp.pop_back();

        dfs(i + 1, nums, t, temp, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(0, nums, target, temp, res);
        return res;
    }
};
