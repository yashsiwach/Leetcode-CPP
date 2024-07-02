class Solution {
public:
    vector<int> intersect(vector<int>& n1, vector<int>& n2) {
        vector<int>v;
        for(int i=0;i<n1.size();i++)
        {
            for(int j=0;j<n2.size();j++)
            {
                if(n1[i]==n2[j])
                {
                    v.push_back(n2[j]);
                    n2[j]=-1;break;
                }
            }
        }
        return v;
        
    }
};