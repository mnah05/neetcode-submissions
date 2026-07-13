class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 2);
        for(int i = n - 1; i >= 0; i--) {
            int skip = dp[i + 1];
            int pick = nums[i] + dp[i + 2];
            dp[i] = max(pick,skip);
        }
        return dp[0];
    }
};
