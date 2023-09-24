class Solution {
public:
    bool isvowel(char a)
    {
        if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'||a=='A'||a=='E'||a=='I'||a=='O'||a=='U')
        {
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int l=0;
        int h=s.length()-1;
        
        while(l<h)
        {
            if(!isvowel(s[l])) l++;
            else if(!isvowel(s[h])) h--;
            else if(isvowel(s[l])&&isvowel(s[h]))
            {
                swap(s[l],s[h]);
                l++;
                h--;
            }
        }return s;
    }
};