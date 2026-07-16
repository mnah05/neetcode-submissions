class Solution {
public:
    vector<int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target + 1, -1);
        return dfs(nums, target);
    }
    int dfs(vector<int>& nums, int t) {
        if (t == 0) return 1;
        if (t < 0) return 0;
        if (dp[t] != -1) return dp[t];
        
        int res = 0;
        for (int num : nums) {
            if (num <= t) {
                res += dfs(nums, t - num);
            }
        }
        return dp[t] = res;
    }
};