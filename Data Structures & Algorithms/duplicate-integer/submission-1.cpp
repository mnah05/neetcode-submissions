class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return false; // No duplicates possible with 0 or 1 element
        
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                return true; // Found a duplicate
            }
        }
        
        return false; // No duplicates found
    }
};
