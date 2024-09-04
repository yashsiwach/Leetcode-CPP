class Solution {
public:
    int robotSim(vector<int>& v, vector<vector<int>>& o) {
        set<pair<int, int>> st;
        for(auto &it:o)
        {
            st.insert({it[0],it[1]});
        }
        int curr = 0;
        set<pair<int,int>>final;
        pair<int, int> point = {0, 0};
        for (auto& it : v) {
            
            if (it == -1) {
                curr=(curr+1)%4;
                continue;
            } else if (it == -2) {
                curr=(curr-1+4)%4;
                continue;
            }
            if (curr == 0) {
                while (it--) {
                    point.second++;
                    if (st.find(point) != st.end()) {
                        point.second--;
                        break;
                    }
                }
            }
            if (curr == 1) {
                while (it--) {
                    point.first++;
                    if (st.find(point) != st.end()) {
                        point.first--;
                        break;
                    }
                }
            }
            if (curr == 2) {
                while (it--) {
                    point.second--;
                    if (st.find(point) != st.end()) {
                        point.second++;
                        break;
                    }
                }
            }
            if (curr == 3) {
                while (it--) {
                    point.first--;
                    if (st.find(point) != st.end()) {
                        point.first++;
                        break;
                    }
                }
            }
            final.insert(point);
           // cout<<point.first<<" "<<point.second<<endl;
        }
        point=*final.rbegin();
        return (point.first*point.first)+(point.second*point.second);
    }
};