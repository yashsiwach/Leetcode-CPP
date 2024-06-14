class Solution {
public:
    int minIncrementForUnique(vector<int>& v) {
        int count=0;
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]>=v[i])
            {
                count+=(v[i-1]+1-v[i]);
            v[i]=v[i-1]+1;
            }
        }
        return count;
    }
};