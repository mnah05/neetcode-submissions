class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> seen;
        for(auto num : nums)
        {
            if(seen.find(num) != seen.end())
            {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
