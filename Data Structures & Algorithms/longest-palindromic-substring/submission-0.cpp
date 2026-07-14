class Solution {
   public:
    string longestPalindrome(string s) {
        int index = 0, resLen = 1;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // dp[i][i] will always be true
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < n - i + 1; j++) {
                int idx = j + i - 1;

                if (s[j] == s[idx] && i == 2) {
                    dp[j][idx] = true;
                    resLen = 2;
                    index = j;
                } else if (s[j] == s[idx] && dp[j + 1][idx - 1] == true) {
                    dp[j][idx] = true;
                    resLen = i;
                    index = j;
                }
            }
        }

        return s.substr(index, resLen);
    }
};