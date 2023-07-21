class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
          int n=nums.size();
          vector<pair<int,int>>lisfq(n);
        lisfq[0].first=1;
        lisfq[0].second=1;
        int lo=1;
        for(int i=1;i<nums.size();i++){
            int mx=0;
            int c=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(lisfq[j].first>mx){
                        mx=lisfq[j].first;
                        c=lisfq[j].second;
                    }
                    else if(lisfq[j].first==mx){
                      c=c+lisfq[j].second;
                    }
                }
            }
           lisfq[i].second=c;
            lisfq[i].first=mx+1;
            if(lo<lisfq[i].first){
               lo=lisfq[i].first; 
            }
        }
        int count=0;
     
        for(int i=0;i<nums.size();i++){
            if(lisfq[i].first==lo){
                count+=lisfq[i].second;
            }
        }
        return count;
    }
};