class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count=0,i=0,j=1;
        while(j<bank.size())
        {
            int one=0,one1=0;
            for(auto it:bank[i])if(it=='1')one++;
            for(auto it:bank[j])if(it=='1')one1++;
            if(one1==0)j++;
            else
            {
                count+=one*one1;
                i=j;
                j++;
            }
        }
        return count;
    }
};