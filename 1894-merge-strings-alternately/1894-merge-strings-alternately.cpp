class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=0;
        string ans="";
        if (word1.length()>word2.length())
        {
            m=word1.length();
        }
        else{
            m=word2.length();
        }
        for(int i=0;i<m;i++)
        {

            if (i<word1.length())
            ans.push_back(word1[i]);
            if(i<word2.length()){
            ans.push_back(word2[i]);}
            


        }return ans;
        
    }
};