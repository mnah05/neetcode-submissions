class Solution {
    public int characterReplacement(String s, int k) {
        Map<Character, Integer> mpp = new HashMap<>();

        int l = 0;
        int maxf = 0;
        int res = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s.charAt(r);

            mpp.put(c, mpp.getOrDefault(c, 0) + 1);
            maxf = Math.max(maxf, mpp.get(c));

            while ((r - l + 1) - maxf > k) {
                char left = s.charAt(l);
                mpp.put(left, mpp.get(left) - 1);
                l++;
            }

            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}