class Solution {
public:
    map<string,int>mp;
    int rec(set<string>&se,string word){
        if(mp.find(word)!=mp.end())return mp[word];
        int ans=1;
        for(int i=0;i<word.size();i++){
            string pred=word.substr(0,i)+word.substr(i+1);
            if(se.count(pred)){
                ans=max(ans,1+rec(se,pred));
            }
        }
        return mp[word]=ans;
    }
    int longestStrChain(vector<string>&words){
        set<string>se(words.begin(),words.end());
        int ans=0;
        for(const string&word:words){
            ans=max(ans,rec(se,word));
        }
        return ans;
    }
};
