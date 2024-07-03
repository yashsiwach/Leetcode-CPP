class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        queue<pair<int,int>>q;
        int n=image.size();
        int m=image[0].size();
        q.push({sr,sc});
        int oldColor = image[sr][sc];
          if (oldColor == color) return image;
        image[sr][sc]=color;
        vector<int> a = {-1, 0, 1, 0};
        vector<int> b = {0, 1, 0, -1};
        while(!q.empty())
        {
            pair<int,int>temp=q.front();
            q.pop();
            int i=temp.first;
            int j=temp.second;
            for (int k = 0; k < 4; k++) { 
                int row = i + a[k]; 
                int col = j + b[k];
                if (row >= 0 && row < n && col >= 0 && col < m&&image[row][col]==oldColor ) {
                    q.push({row,col});
                    image[row][col]=color;
                }
            }
        }
        return image;
    }
};