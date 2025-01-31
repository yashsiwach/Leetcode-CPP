class Solution {
public:
    unordered_map<string, int> mp;

    int rec(unordered_set<string>& wordsSet, string word) {
        if (mp.find(word) != mp.end()) return mp[word];

        int maxLen = 1;
        for (int i = 0; i < word.size(); i++) {
            string pred = word.substr(0, i) + word.substr(i + 1);
            if (wordsSet.count(pred)) {
                maxLen = max(maxLen, 1 + rec(wordsSet, pred));
            }
        }
        return mp[word] = maxLen;
    }

    int longestStrChain(vector<string>& words) {
        unordered_set<string> wordsSet(words.begin(), words.end());
        int maxChain = 0;

        for (const string& word : words) {
            maxChain = max(maxChain, rec(wordsSet, word));
        }
        return maxChain;
    }
};
