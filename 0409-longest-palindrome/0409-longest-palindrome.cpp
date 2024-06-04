class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int>mp;
        int count=0;
        for(auto it:s)mp[it]++;
        for(auto it:mp)count+=(it.second/2)*2;
        if(s.size()==count)return count;
        else return count+1;
        

    }
};