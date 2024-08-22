class Solution {
public:
    int findComplement(int n) {
        return n^ (2*( (1<<int(log2(n)) ) -1) | 1);
    }
};