class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char,int> mpp;
        for(char it : s){
            mpp[it]++;
        }
        for(auto it : t){
            mpp[it]--;
            if(mpp[it] == 0){
                mpp.erase(it);
            }
        }
        return mpp.empty();
    }
};
