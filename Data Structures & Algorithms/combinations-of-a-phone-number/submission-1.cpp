class Solution {
   public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        dfs(0, "", digits);
        return res;
    }

    void dfs(int i, string curr, const string& digits) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            dfs(i + 1, curr+ c, digits);
        }
    }
};
