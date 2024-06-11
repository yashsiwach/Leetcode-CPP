class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>v,u;
        map<int,int>a,b;
        for(int i=0;i<arr2.size();i++)
        {
            a[arr2[i]]++;
        }
        for(int i=0;i<arr1.size();i++)
        {
            if(a.find(arr1[i])==a.end())
            {
              v.push_back(arr1[i]);
            }           
        }
        for(auto it:arr1)
        {
            b[it]++;
        }
        for(auto it:arr2)
        {
            int amount=b[it];
            while(amount>0){u.push_back(it);amount--;}
        }
        
        sort(v.begin(),v.end());
        for(auto it:v)
        {
            u.push_back(it);
        }
        return u;
    }
};