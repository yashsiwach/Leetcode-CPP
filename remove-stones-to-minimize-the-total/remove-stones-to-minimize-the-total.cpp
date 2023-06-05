class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxheap;
        for(int i=0;i<piles.size();i++)
        {
            maxheap.push(piles[i]);
        }
        while(k--)
        {
            int max=maxheap.top();
            maxheap.pop();
            max=max-floor(max/2);
            maxheap.push(max);
        }
        int sum=0;
        while(!maxheap.empty())
        {
            int temp=maxheap.top();
            maxheap.pop();
            sum+=temp;
        }return sum;
        
    }
};