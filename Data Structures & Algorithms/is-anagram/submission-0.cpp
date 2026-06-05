class Solution {
public:
    bool isAnagram(string s, string t) {
        //hash map
        if(s.size() != t.size()) return false;
        map<char,int> mpp;
        //hashing strin s
        for(char i : s){
            mpp[i]++;
        }
        //checking characters form t and removing similar characters from s
        for(char it : t){
            mpp[it]--;
            if(mpp[it] == 0){
                mpp.erase(it);
            }
        }
        return mpp.empty();
    }
};
