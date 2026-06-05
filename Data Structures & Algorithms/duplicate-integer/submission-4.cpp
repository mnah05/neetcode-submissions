class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(auto i : nums){
            mpp[i]++;
            if(mpp[i] > 1){
                return true;
            }
        }
        return false;
    }
};
