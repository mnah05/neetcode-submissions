class Solution {
   public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while (st.find(n) == st.end()) {
            st.insert(n);
            n = sumOf(n);
            if (n == 1) {
                return true;
            }
        }
        return false;
    }
    int sumOf(int n) {
        int output = 0;

        while (n > 0) {
            int digit = n % 10;
            digit = digit * digit;
            output += digit;
            n /= 10;
        }
        return output;
    }
};
