class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> mpp = new HashMap<>();
        int l = 0, ans = 0;

        for (int r = 0; r < s.length(); r++) {
            char ch = s.charAt(r);

            if (mpp.containsKey(ch) && mpp.get(ch) >= l) {
                l = mpp.get(ch) + 1;
            }

            mpp.put(ch, r);
            ans = Math.max(ans, r - l + 1);
        }

        return ans;
    }
}