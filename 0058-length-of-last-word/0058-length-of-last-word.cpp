class Solution {
public:
    int lengthOfLastWord(string s) {
        int count=0;
        string temp=" ";
        for(auto it=s.rbegin();it!=s.rend();it++)
        {
            if(count>0&&isspace(*it)){
                break;

            }
            if(isspace(*it)){
                continue;   
            }
            else 
            {
                count++;
            }
            
        }
    
        return count;
    }
};