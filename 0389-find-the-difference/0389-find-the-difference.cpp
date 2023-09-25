class Solution {
public:
    char findTheDifference(string s, string t) {
   
        char an;
        for(auto it:t)
        {
            int ans=s.find(it);
            
            if(ans==string::npos)
            {
                 an=it; 
            }
            else s[ans]=';';
        }return an;
    }
};