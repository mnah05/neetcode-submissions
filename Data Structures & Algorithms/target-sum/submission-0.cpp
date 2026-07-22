class Solution {
   public:
    map<pair<int, int>, int> memo;

    int helper(vector<int>& nums, int t, int i, int currSum) {
        pair<int, int> key = {i, currSum};
        if (memo.count(key)) return memo[key];

        if (i == nums.size()) {
            return currSum == t ? 1 : 0;
        }

        int plus = helper(nums, t, i + 1, currSum + nums[i]);
        int minus = helper(nums, t, i + 1, currSum - nums[i]);

        return memo[key] = plus + minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) { return helper(nums, target, 0, 0); }
};