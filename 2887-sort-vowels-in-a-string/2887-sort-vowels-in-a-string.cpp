class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string sortVowels(string s) {
        vector<char> vowels;
        string consonants;

        for (char c : s) {
            if (isVowel(c)) {
                vowels.push_back(c);
            } else {
                consonants.push_back(c);
            }
        }

        std::sort(vowels.begin(), vowels.end());

        string result;
        size_t vowelIdx = 0, consonantIdx = 0;

        for (char c : s) {
            if (isVowel(c)) {
                result += vowels[vowelIdx++];
            } else {
                result += consonants[consonantIdx++];
            }
        }

        return result;
    }
};



