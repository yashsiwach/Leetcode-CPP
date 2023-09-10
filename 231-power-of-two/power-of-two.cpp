class Solution {
public:
    bool isPowerOfTwo(int n) {
        bitset<64> binary(n);
        if(__builtin_popcount(n)==1&&n>0)
        {
            return true;
        }
        return false;
        
    }
};