class Solution {
   public:
    void dfs(int op, int cl, int n, vector<string>& res, string& curr) {
        if (op == n && cl == n) {
            res.push_back(curr);
            return;
        }

        if (op < n) {
            curr.push_back('(');
            dfs(op + 1, cl, n, res, curr);
            curr.pop_back();
        }

        if (cl < op) {
            curr.push_back(')');
            dfs(op, cl + 1, n, res, curr);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        dfs(0, 0, n, res, curr);
        return res;
    }
};