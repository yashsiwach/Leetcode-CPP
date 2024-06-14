class Solution {
public:
    int minIncrementForUnique(vector<int>& v) {
        sort(v.begin(),v.end());
        int count=0;
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
            {
                count+=(v[i-1]+1)-v[i];
                v[i]=v[i-1]+1;
            }
        }
        return count;
        
    }
};