class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        multiset<pair<int,int>>mp;
        vector<int>v;
        int sum =0;
        for(int i=0;i<mat.size();i++)
        {
            sum=0;
            for(auto j:mat[i])
            {
                if(j==1)
                {
                    sum++;
                }
            }
            mp.insert({sum,i});
        }
        int count=0;
        for(auto it:mp)
        {
            if(count==k) break;
            v.push_back(it.second);
            count++;
        }
        return v;
    }
};