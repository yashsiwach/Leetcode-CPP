class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> ans(people.size());

        // So we want to view flowers as separated start and end events. Lets first
        // break it out into that.
        // Create an array of start flower events and end flower events.
        vector<int> flower_starts;
        vector<int> flower_ends;

        for (const auto& flower : flowers)
        {
            flower_starts.push_back(flower[0]);
            // We add 1 since the flower intervals as given are inclusive,
            // meaning the actual timeslot where the flower stops blooming is
            // one past the provided time.
            flower_ends.push_back(flower[1] + 1);
        }

        vector<pair<int, int>> people_with_id;
        people_with_id.reserve(people.size());

        // Sort the people by time, while also tracking what their original ID was.
        for (int i = 0; i < people.size(); i++)
        {
            people_with_id.push_back(make_pair(people[i], i));
        }

        // Sort all of our event queues by time.
        sort(flower_starts.begin(), flower_starts.end());
        sort(flower_ends.begin(), flower_ends.end());
        sort(people_with_id.begin(), people_with_id.end());

        // Indices of next flower start + end events respectively.
        int next_flower_start = 0;
        int next_flower_end = 0;

        // Tracks the current number of bloomed flowers.
        int num_flowers = 0;

        // For each person calculate how many flowers they see.
        for (int i = 0; i < people_with_id.size(); i++)
        {
            int target_time = people_with_id[i].first;
            int person_id = people_with_id[i].second;
            
            // Process all flower events that occur up until and including
            // the target time.
            while (next_flower_start < flower_starts.size() &&
                flower_starts[next_flower_start] <= target_time)
            {
                // A flower has bloomed.
                num_flowers++;
                next_flower_start++;
            }

            while (next_flower_end < flower_ends.size() && flower_ends[next_flower_end] <= target_time)
            {
                num_flowers--;
                next_flower_end++;
            }

            // Record the number of flowers this person sees in the answer log.
            ans[person_id] = num_flowers;
        }

        return ans;
    }
};