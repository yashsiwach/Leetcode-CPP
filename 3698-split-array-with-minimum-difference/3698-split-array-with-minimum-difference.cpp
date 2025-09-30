class Solution {
public:
    long long splitArray(vector<int>& v) {
        long long n=v.size();
        vector<pair<long long,bool>>left(n),right(n);
        for(long long i=0;i<n;i++){
            if(i==0){
                left[i].first=v[0];
                left[i].second=true;
            }
            else{
                left[i].first=left[i-1].first+v[i];
                left[i].second=(left[i-1].first<left[i].first?true:false);
            }
        }
        for(long long i=n-1;i>=0;i--){
            if(i==n-1){
                right[i].first=v[i];
                right[i].second=true;
            }
            else{
                right[i].first=right[i+1].first+v[i];
                right[i].second=(right[i]>right[i+1]?true:false);
            }
        }

        long long mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            long long l=i,r=i+1;
            if(left[l].second==true&&right[r].second==true){
                long long cost=abs(left[l].first-right[r].first);
                mini=min(mini,cost);
            }
        }
        return mini==0?-1:mini;
    }
};