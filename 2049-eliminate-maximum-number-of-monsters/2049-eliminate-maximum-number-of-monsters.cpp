class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
            vector<double>v;
            for(int i=0;i<dist.size();i++)
            {
                double temp=(double)dist[i]/(double)speed[i];
                v.push_back(temp);
            }
            int counter=0;
            sort(v.begin(),v.end());
            for(int i=0;i<dist.size();i++)
            {
                double diff=v[i]-counter;
                if(diff<=0)break;
                else
                {
                    counter++;
                }
            }
            return counter;
    }
};