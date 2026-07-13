class Solution {
   public:
    int dp[101];
    // goal is to get out of bounds
    int sol(vector<int>& cost, int curr_index) {
        if (curr_index >= cost.size()) {
            return 0;
        }
        if (dp[curr_index] != -1) {
            return dp[curr_index];
        }
        int sum1 = cost[curr_index] + sol(cost, curr_index + 1);
        int sum2 = cost[curr_index] + sol(cost, curr_index + 2);

        return dp[curr_index] = min(sum1, sum2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        fill(dp, dp + 101, -1);
        return min(sol(cost, 0), sol(cost, 1));
    }
};
