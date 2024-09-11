class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans = start ^ goal;
        int setBits = 0;
        while(ans > 0) {
            ans = ans & (ans - 1);
            setBits++;
        }
        return setBits;
    }
};