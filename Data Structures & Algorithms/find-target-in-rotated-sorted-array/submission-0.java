class Solution {
    public int search(int[] nums, int target) {
        int l = 0;
        int r = nums.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            //if left half is sorted
            if (nums[l] <= nums[mid]) {
                //if its target is within range of left half
                if (target >= nums[l] && target < nums[mid]) {
                    //terminate right half
                    r = mid - 1;
                } else {
                    //else target is in right half
                    l = mid + 1;
                }
            } else {
                //same logic but in reverse
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
}
