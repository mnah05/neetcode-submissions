class Solution {
    public boolean hasDuplicate(int[] nums) {
        boolean hasDusplicate = false;
        int st;
        for (int i = 0; i < nums.length; i++) {
            st = nums[i];
            for (int j = i +1; j < nums.length; j++) {
                if(st == nums[j]) {
                    hasDusplicate = true;
                    break;
                }
            }
        }
        return  hasDusplicate;
    }
}
