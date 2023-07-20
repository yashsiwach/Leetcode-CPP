class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> temp;
        for (int i = 0; i < asteroids.size(); i++) {
            if (temp.empty() || asteroids[i] > 0) {
                temp.push(asteroids[i]);
            } else {
                while (!temp.empty() && temp.top() > 0 && temp.top() < abs(asteroids[i])) {
                    temp.pop();
                }
                if (temp.empty() || temp.top() < 0) {
                    temp.push(asteroids[i]);
                } else if (temp.top() == abs(asteroids[i])) {
                    temp.pop();
                }
            }
        }

        while (!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
