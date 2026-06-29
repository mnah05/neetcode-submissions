class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> temp;
        dfs(temp, nums, pick);
        return res;
    }

    void dfs(vector<int>& t, vector<int>& nums, vector<bool>& pick) {
        if (t.size() == nums.size()) {
            res.push_back(t);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (pick[i] != true) {
                t.push_back(nums[i]);
                pick[i] = true;
                dfs(t, nums, pick);
                t.pop_back();
                pick[i] = false;
            }
        }
    }
};
