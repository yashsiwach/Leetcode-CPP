class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int hashTable[26]={0};
        int c=0;

        for(int i=0;i<allowed.length();i++){
            hashTable[allowed[i]-'a']++;
        }
        for(int i=0;i<words.size();i++){
            string ans=words[i];
            bool count=true;
            for(int j=0;j<ans.length();j++){
                if(hashTable[ans[j]-'a']==0){
                    count=false;
                    break;
                }
            }
            if(count){
                c++;
            }
        }
        return c;
    }
};