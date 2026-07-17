class Solution {
public:
    unordered_map<int,int> dp;
    int dfs(int t) {
        if (t == 0) return 0;
        if (dp.count(t)) return dp[t];

        int res = t;
        for(int i = 1; i * i <= t; i++){
            res = min(res,1+dfs(t - i*i));
        }
        return dp[t] = res;
    }
    int numSquares(int n) {
        return dfs(n);
    }
};