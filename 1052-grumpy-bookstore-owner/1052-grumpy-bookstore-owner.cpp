class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& g, int m) {
        int i=0,j=0,count=0,maxi=0;
        pair<int,int>p;
        for(int i=0;i<c.size();i++)
        {
            if(g[i]==1)count+=c[i];
            if(i-j+1==m)
            {
                if(count>maxi)
                {
                    p={j,i};
                    maxi=count;
                    cout<<maxi<<" "<<j<<" "<<endl;
                }
                count-=c[j];
                j++;
            }
            
        }
        int ans=0;
        cout<<p.first<<" "<<p.second<<endl;
        for(int i=0;i<c.size();i++)
        {
            if(g[i]==0||i>=p.first&&i<=p.second)ans+=c[i];
        }
        return ans;
    }
};