class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : pq(begin(nums), end(nums)), k(k) {
        while (pq.size() > k) pq.pop();
    }
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<>> pq;
    int k;
};
