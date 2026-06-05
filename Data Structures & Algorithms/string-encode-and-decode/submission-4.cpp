
class Solution {
public:
    // Method to encode the vector of strings into a single string
    string encode(vector<string>& strs) {
        string s = "";
        for (int i = 0; i < strs.size(); i++) {
            // Convert the length of the string to string and concatenate
            s += to_string(strs[i].length()) + "#" + strs[i];
        }
        return s;
    }

    // Method to decode the encoded string back into a vector of strings
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;

        while (i < s.length()) {
            int j = i;
            // Find the position of '#'
            while (s[j] != '#') {
                j++;
            }
            // Get the length of the substring
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            // Append the substring to the result vector
            res.push_back(s.substr(i, length));
            i = j;
        }

        return res;
    }
};

