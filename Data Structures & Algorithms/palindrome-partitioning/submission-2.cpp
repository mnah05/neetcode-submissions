class Solution {
   public:
    vector<vector<string>> res;

    bool isPal(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    void dfs(int idx, const string& s, vector<string>& curr) {
        if (idx == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                curr.push_back(s.substr(idx, i - idx + 1));
                dfs(i + 1, s, curr);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> curr;
        dfs(0, s,curr);
        return res;
    }
};