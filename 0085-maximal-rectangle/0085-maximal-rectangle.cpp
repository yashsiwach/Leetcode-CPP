#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    //l: the x-coordinate of the bar to the left with height h[l] < h[i].
    //r: the x-coordinate of the bar to the right with height h[r] < h[i].
    int largestRectangleArea(vector<int>& heights, int n) {
        //adopt from leetcode 84 which is a 2-pass solution using DP
        if (n==0) return 0;
        vector<int> l(n),  r(n);
        r[n-1]=n, l[0]=-1;

        for(int i=1; i<n; i++){
            int p=i-1;
            while(p>=0 && heights[p]>=heights[i])
                p=l[p];
            l[i]=p;
        }

        int maxA=heights[n-1]*(r[n-1]-l[n-1]-1);
        for(int i=n-2; i>=0; i--){
            int p=i+1;
            while(p<n && heights[p]>=heights[i])
                p=r[p];
            r[i]=p;
            maxA=max(maxA, heights[i]*(r[i]-l[i]-1));
        }
    //    cout<<maxA<<endl;
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        const unsigned short row=matrix.size(), col=matrix[0].size();
        if (row==1 && col==1) return matrix[0][0]=='1';
        vector<int> h(col);//height 
        int maxArea=0;

        for(int i=0; i<row; i++){
            for (int j=0; j<col; j++){
                // Count the successive '1's & store in h[j]
                h[j]=(matrix[i][j]=='0')?0:h[j]+1;
            }
            maxArea=max(maxArea, largestRectangleArea(h, col));
        }
        return maxArea;
    }
};