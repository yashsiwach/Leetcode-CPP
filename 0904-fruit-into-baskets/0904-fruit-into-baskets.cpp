class Solution {
public:
    int totalFruit(vector<int>& v) {
        unordered_map<int,int>mp;
        int i=0,j=0,count=0;
        while(i<v.size())
        {
            mp[v[i]]++;
            if(mp.size()>2)
            {
               count=max(count,i-j);
               while(mp.size()>2)
               {
                   mp[v[j]]--;
                   if(mp[v[j]]==0)mp.erase(v[j]);
                   j++;
               }
            }
            else if(i==v.size()-1)
            {
                count=max(count,i-j+1);
            }
            i++;
        }
        return count;
    }
};
