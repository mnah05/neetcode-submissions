class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s.size() > 2)
            return false;

        if (s[0] == '0')
            return false;

        int num = stoi(s);

        return num >= 1 && num <= 26;
    }

    int numDecodings(string s) {
        int n = s.size();

    
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n && j < i + 2; j++) {
                temp += s[j];
                if (isValid(temp))
                    dp[i][j] = true;
            }
        }

    
        vector<int> ways(n + 1, 0);
        ways[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n && j < i + 2; j++) {
                if (dp[i][j]) {
                    ways[i] += ways[j + 1];
                }
            }
        }

        return ways[0];
    }
};