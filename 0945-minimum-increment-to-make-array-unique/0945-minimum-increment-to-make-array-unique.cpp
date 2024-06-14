class Solution {
public:
    int minIncrementForUnique(vector<int>& v) {
        sort(v.begin(),v.end());
        int count=0;
        set<int>st{v[0]};
        for(int i=1;i<v.size();i++)
        {
            if(st.find(v[i])!=st.end())
            {
                int maxi=*st.rbegin();
                count+=(maxi+1)-v[i];
                st.insert(maxi+1);
                cout<<count<<" "<<v[i]<<endl;
            }
            else st.insert(v[i]);

        }
        return count;
        
    }
};