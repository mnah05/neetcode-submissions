class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //using Extra space
        int n = nums.size();
        vector<int> ans(n);
        //for prefix
        vector<int> left(n);
        //for suffix
        vector<int> right(n);
        //for left side
        left[0] = 1; //because nothing before 0th index so assuming 1;
        for(int i = 1; i < n; i++){
            left[i] = left[i - 1] * nums[i - 1];
        }
        //for right side
        right[n-1] = 1; //same as previos but in reverse
        for(int i = n - 2; i>= 0;i--){
            right[i] = right[i + 1] * nums[i + 1];
        }
        // solution
        for(int i = 0; i < n; i++){
            ans[i] = right[i] * left[i];
        }
        return ans;
    }
};
