class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        map<char, int> mp, mp1;

        for (auto it : p) {
            mp1[it]++;
        }

        int n = p.length();
        int i = 0, j = 0;

        while (j < s.length()) {
            mp[s[j]]++;

            if ((j - i) + 1 < n) {
                j++;
            } else {
                
                cout<<endl;
               
                
                if (mp==mp1) {
                    ans.push_back(i);
                }

                // Move the window to the right
              
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }

                // Increment both i and j
                i++;
                j++;
            }
        }

        return ans;
    }
};