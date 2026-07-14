class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int temp1 = 1; // dp[i+1]
        int temp2 = 0; // dp[i+2]

        for (int i = n - 1; i >= 0; i--) {

            int current = 0;

            if (s[i] != '0') {

                current = temp1;

                if (i + 1 < n) {
                    int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                    if (num >= 10 && num <= 26) {
                        current += temp2;
                    }
                }
            }

            // Move the window
            temp2 = temp1;
            temp1 = current;
        }

        return temp1;
    }
};