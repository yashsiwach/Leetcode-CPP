#include <vector>
using namespace std;

class Solution {
public:
    bool solve(int i, int k, vector<int>& stones, int n) {
        if (i == n) return true;

        // Check all possible jump sizes for the current stone
        for (int j = i + 1; j < stones.size(); ++j) {
            int gap = stones[j] - stones[i];
            if (gap >= k - 1 && gap <= k + 1) {
                if (solve(j, gap, stones, n)) return true;
            } else if (gap > k + 1) {
                break; // No need to check further if gap is too large
            }
        }

        return false;
    }

    bool canCross(vector<int>& stones) {
        int n = stones.size() - 1;
       
