class Solution {
public:
    int nthUglyNumber(int n) {
        std::set<long> v = {1};
        auto it = v.begin(); // Iterator to the set
int count=0;
        while ( count< n) {
            v.insert(*it * 2);
            v.insert(*it * 3);
            v.insert(*it * 5);
            count++;
            ++it;
        }

        // Reset the iterator to the beginning
        it = v.begin();
        // Advance the iterator to the nth element
        std::advance(it, n - 1);
        for(auto it:v)cout<<it<<" ";
        return *it;
    }
};