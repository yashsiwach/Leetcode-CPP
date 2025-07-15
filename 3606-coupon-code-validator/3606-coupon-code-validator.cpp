class Solution {
public:
bool check(string &s){
    for(int i=0;i<s.size();i++){
        if(!isalnum(s[i]) && s[i] != '_')return false;
    }return true;
}
bool c2(string &s){
    if(s=="electronics"||s=="grocery"||s=="pharmacy"||s=="restaurant")return true;
    return false;
}
    vector<string> validateCoupons(vector<string>& c, vector<string>& bl, vector<bool>& isa) {
        map<string,multiset<string>>mp;
        for(int i=0;i<c.size();i++){
            if(isa[i]&&check(c[i])&&c[i].size()>0&&c2(bl[i])){
                mp[bl[i]].insert(c[i]);
            }
        }
        vector<string>ans;
        for(auto it:mp){
            for(auto x:it.second){
                ans.push_back(x);
            }
        }
        return ans;
    }
};