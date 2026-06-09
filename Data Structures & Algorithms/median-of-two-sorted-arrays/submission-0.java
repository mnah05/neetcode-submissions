class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int[] merged = new int[nums1.length + nums2.length];

        int index = 0;

        for (int num : nums1) {
            merged[index++] = num;
        }

        for (int num : nums2) {
            merged[index++] = num;
        }

        Arrays.sort(merged);

        int total = merged.length;

        if (total % 2 == 1) {
            return (double) merged[total / 2];
        } else {
            int middle1 = merged[total / 2 - 1];
            int middle2 = merged[total / 2];
            return (middle1 + middle2) / 2.0;
        }
    }
}