class Solution {
   public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT;
        unordered_map<char, int> window;

        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        int resLen = INT_MAX;
        int resL = -1, resR = -1;

        int l = 0;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if (r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    resL = l;
                    resR = r;
                }

                char leftChar = s[l];
                window[leftChar]--;

                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(resL, resLen);
    }
};