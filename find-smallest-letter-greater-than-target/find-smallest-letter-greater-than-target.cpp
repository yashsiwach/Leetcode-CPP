class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // set<int>jat;
        // if(letters[letters.size()-1]<=target)
        // {
        //     return letters[0];
        // }
        // for(int i=0;i<letters.size();i++)
        // {
        //     if(letters[i]>target){
        //     int temp=letters[i]-target;
        //     if(temp==0)
        //     {
        //         return letters[i+1];
        //     }
        //     jat.insert(temp);}
        // }
        // return target+*jat.begin();
        int i=upper_bound(letters.begin(), letters.end(), target)-letters.begin();
        return (i==letters.size())?letters[0]:letters[i];


        
    }
};