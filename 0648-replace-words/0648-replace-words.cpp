class Trie {
public:
    bool terminal;
    Trie* next[26]; // Array of pointers to child nodes (one for each letter)

    Trie() {
        terminal = false;
        for (int i = 0; i < 26; i++) {
            next[i] = NULL;
        }
    }
};

class Solution {
    Trie* root = new Trie(); // Root node of the trie

public:
    void insert(string word) {
        Trie* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (!curr->next[index]) {
                curr->next[index] = new Trie();
            }
            curr = curr->next[index];
        }
        curr->terminal = true;
    }

    string search(string word) {
        Trie* curr = root;
        int rootLength = 0;
        for (int i = 0; i < word.length(); i++) {
            char c = word.charAt(i);
            int index = c - 'a';
            if (!curr->next[index]) {
                return ""; // No root found
            }
            curr = curr->next[index];
            if (curr->terminal) {
                rootLength = i + 1; // Update shortest root length if found
            }
        }
        return word.substring(0, rootLength); // Return the shortest root substring
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        for (string word : dictionary) {
            insert(word);
        }

        string[] words = sentence.split(" "); // Split sentence into words
        StringBuilder result = new StringBuilder();

        for (String word : words) {
            String root = search(word);
            result.append(root).append(" ");
        }

        return result.toString().trim(); // Remove trailing whitespace
    }
};