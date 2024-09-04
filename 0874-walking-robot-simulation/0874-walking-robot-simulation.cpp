class Solution {
public:
    int robotSim(vector<int>& v, vector<vector<int>>& o) {
        set<pair<int, int>> st;
        for(auto &it : o) {
            st.insert({it[0], it[1]});
        }
        int curr = 0;  // 0 -> North, 1 -> East, 2 -> South, 3 -> West
        pair<int, int> point = {0, 0};
        int maxDist = 0;
        
        for (auto& it : v) {
            if (it == -1) {
                curr = (curr + 1) % 4;  // Right turn
            } else if (it == -2) {
                curr = (curr - 1 + 4) % 4;  // Left turn, ensuring curr is non-negative
            } else {
                for (int i = 0; i < it; ++i) {
                    if (curr == 0) point.second++;  // Move North
                    if (curr == 1) point.first++;   // Move East
                    if (curr == 2) point.second--;  // Move South
                    if (curr == 3) point.first--;   // Move West
                    
                    if (st.find(point) != st.end()) {  // Check for obstacles
                        if (curr == 0) point.second--;
                        if (curr == 1) point.first--;
                        if (curr == 2) point.second++;
                        if (curr == 3) point.first++;
                        break;
                    }
                }
            }
            maxDist = max(maxDist, point.first * point.first + point.second * point.second);
        }
        
        return maxDist;
    }
};
