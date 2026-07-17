class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& st, int i) {
        if (i >= st.size())
            return 0;

        if (dp[i] != INT_MIN)
            return dp[i];

        int res = INT_MIN;
        int take = 0;

        // 3 calls per recursive call
        for (int k = 0; k < 3 && i + k < st.size(); k++) {
            take += st[i + k];
            res = max(res, take - solve(st, i + k + 1));
        }

        return dp[i] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, INT_MIN);

        int score = solve(stoneValue, 0);

        if (score > 0)
            return "Alice";
        if (score < 0)
            return "Bob";
        return "Tie";
    }
};