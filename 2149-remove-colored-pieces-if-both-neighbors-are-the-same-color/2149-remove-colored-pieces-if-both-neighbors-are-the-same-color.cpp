class Solution {
public:
    bool winnerOfGame(string colors) {
        int counta=0;
        int countb=0;
        int tempa=0,tempb=0;
        for(auto i:colors)
        {
            if(i=='A'&&tempa>=2) counta++;
            if(i=='B'&&tempb>=2) countb++;
            if(tempa>0&&i=='B') tempa=0;
            if(tempb>0&&i=='A') tempb=0;
            if(i=='A') tempa++;
            if(i=='B') tempb++;
        }
        if(counta>countb) return true;
        else return false;
        
    }
};