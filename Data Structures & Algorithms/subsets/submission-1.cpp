class Solution {
   public:
    void dfs(int i, const vector<int>& nums, vector<int>& temp, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(temp);
            return;
        }

        temp.push_back(nums[i]);
        dfs(i + 1, nums, temp, res);
        temp.pop_back();
        dfs(i + 1, nums, temp, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        dfs(0, nums, sub, res);
        return res;
    }
};
