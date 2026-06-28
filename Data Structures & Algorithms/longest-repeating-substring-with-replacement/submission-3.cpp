class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int l = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            // at every insertion, we calculate the max freq
            maxFreq = max(maxFreq, freq[s[r]]);
            
            //when shrinking we see the valid size of a window
            //if curr window size > k then shrink
            while (((r - l + 1) - maxFreq) > k) {
                freq[s[l]]--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};