class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<int> memo(s.size(), -1);

        return dfs(s, wordSet, 0, memo);
    }

    bool dfs(const string& s, const unordered_set<string>& st, int i, vector<int>& memo) {
        if (i == s.size()) {
            return true;
        }

        if (memo[i] != -1) {
            return memo[i];
        }

        string word = "";

        for (int j = i; j < s.size(); j++) {
            word += s[j];   // build word incrementally

            if (st.find(word) != st.end()) {
                if (dfs(s, st, j + 1, memo)) {
                    return memo[i] = true;
                }
            }
        }

        return memo[i] = false;
    }
};