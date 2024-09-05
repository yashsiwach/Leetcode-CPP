class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> jat;
        int n=matrix.size(),m=matrix[0].size();
        int up=0,left=0,right=m-1,down=n-1;
        while(jat.size()<m*n)
        {
            for(int i=left;i<=right&&jat.size()<m*n;i++) jat.push_back(matrix[up][i]);
            for(int i=up+1;i<=down-1&&jat.size()<m*n;i++) jat.push_back(matrix[i][right]);
            for(int i=right;i>=left&&jat.size()<m*n;i--) jat.push_back(matrix[down][i]);
            for(int i=down-1;i>=up+1&&jat.size()<m*n;i--) jat.push_back(matrix[i][left]);
            left++;
            right--;
            up++;
            down--;
        }return jat;
        
    }
};