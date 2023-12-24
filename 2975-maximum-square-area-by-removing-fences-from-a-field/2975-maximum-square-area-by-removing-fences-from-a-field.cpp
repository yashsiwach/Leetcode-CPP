class Solution {
public:
const long long MOD = 1000000007;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        
       
        unordered_set<int>st,st2;
        for(int i=0;i<hFences.size();i++)
        {
            for(int j=i;j<hFences.size();j++)
            {
                long long d=abs(hFences[j]-hFences[i]);
                st.insert(d);
            }
        }
        for(int i=0;i<vFences.size();i++)
        {
            for(int j=i;j<vFences.size();j++)
            {
                long long d=abs(vFences[j]-vFences[i]);
                st2.insert(d);
            }
        }
         vector<int>dis(st.begin(),st.end());
         for(auto &it:st2)dis.push_back(it);
    
        sort(dis.begin(),dis.end());
        long long ans=-1;
        cout<<dis.size()<<endl;
        for(int i=0;i<dis.size()-1;i++)
        {
            if(dis[i]==dis[i+1])ans=dis[i];
        }
        return ans==0?-1:(ans*ans)%MOD;
    }
};