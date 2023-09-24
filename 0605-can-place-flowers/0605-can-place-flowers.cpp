class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 0) {
                // Check if the previous and next positions are also 0 (empty).
                int prev = (i == 0) ? 0 : flowerbed[i - 1];
                int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1];

                if (prev == 0 && next == 0) {
                    flowerbed[i] = 1; // Place a flower at position i.
                    count++;
                }
            }
        }
        
        return count >= n;
    }
};
