class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] output = new int[n - k + 1];

        Deque<Integer> q = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            // [1] Remove indices outside the current window
            while (!q.isEmpty() && q.getFirst() <= i - k) {
                q.removeFirst();
            }

            // [2] Remove smaller elements from the back
            while (!q.isEmpty() && nums[i] >= nums[q.getLast()]) {
                q.removeLast();
            }

            // [3] Add current index
            q.addLast(i);

            // [4] Record answer when first window is complete
            if (i >= k - 1) {
                output[i - k + 1] = nums[q.getFirst()];
            }
        }

        return output;
    }
}