class Solution {
   public:
    int t[5001][2];

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        fill(&t[0][0], &t[0][0] + 5001 * 2, -1);

        return fn(prices, 0, n, true);
    }

    int fn(vector<int>& pri, int d, int n, bool buy) {
        if (d >= n) {
            return 0;
        }

        if (t[d][buy] != -1) {
            return t[d][buy];
        }

        int profit = 0;

        if (buy) {
            int take = fn(pri, d + 1, n, false) - pri[d];
            int not_take = fn(pri, d + 1, n, true);
            profit = max({profit, take, not_take});
        } else {
            int sell = pri[d] + fn(pri, d + 2, n, true);
            int not_sell = fn(pri, d + 1, n, false);
            profit = max({profit, sell, not_sell});
        }

        return t[d][buy] = profit;
    }
};