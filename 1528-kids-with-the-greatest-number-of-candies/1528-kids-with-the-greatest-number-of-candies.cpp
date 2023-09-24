class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool>v;
        auto m=max_element(candies.begin(),candies.end());
        int max=*(m);
        for(auto it:candies)
        {
            if(it+extraCandies<max) v.push_back(false);
            else v.push_back(true);
        }return v;

        
    }
};