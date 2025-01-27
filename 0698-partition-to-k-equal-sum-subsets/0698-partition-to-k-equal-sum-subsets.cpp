#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool rec(vector<int>& v, int k, int temp, int sum, int start, vector<bool>& visi) {
        if (k == 0) {
            return true;
        }

        if (temp == sum) {
            return rec(v, k - 1, 0, sum, 0, visi);
        }

        for (int i = start; i < v.size(); i++) {
            if (!visi[i] && temp + v[i] <= sum) {
                visi[i] = true;
                if (rec(v, k, temp + v[i], sum, i + 1, visi)) {
                    return true;
                }
                visi[i] = false;

                while (i + 1 < v.size() && v[i] == v[i + 1]) {
                    i++; 
                }
            }
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& v, int k) {
        int totalSum = accumulate(v.begin(), v.end(), 0);
        if (totalSum % k != 0) {
            return false;
        }

        int targetSum = totalSum / k;
        sort(v.begin(), v.end(), greater<int>()); 

        if (v[0] > targetSum) {
            return false; 
        }

        vector<bool> visi(v.size(), false);
        return rec(v, k, 0, targetSum, 0, visi);
    }
};