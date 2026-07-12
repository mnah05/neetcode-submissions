class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_map<string, vector<string>> nei;

        wordList.push_back(beginWord);

        for (string& w : wordList) {
            for (int i = 0; i < w.size(); i++) {
                string pattern = w;
                pattern[i] = '*';
                nei[pattern].push_back(w);
            }
        }

        queue<string> q;
        unordered_set<string> vis;

        q.push(beginWord);
        vis.insert(beginWord);

        int level = 1;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string w = q.front();
                q.pop();

                if (w == endWord) return level;

                for (int i = 0; i < w.size(); i++) {
                    string pattern = w;
                    pattern[i] = '*';

                    for (string& neighbor : nei[pattern]) {
                        if (vis.find(neighbor) == vis.end()) {
                            vis.insert(neighbor);
                            q.push(neighbor);
                        }
                    }
                }
            }
            level++;
        }

        return 0;
    }
};