class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        long l = 0;
        long r = Arrays.stream(piles).max().getAsInt();
        int ans = (int) r;

        while (l <= r) {
            long mid = (l + r) / 2;
            long time = 0;
            for (int p : piles) {
                time += Math.ceil((double) p / mid);
            }
            if (time <= h) {
                ans = (int) mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
}
