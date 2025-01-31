class NumMatrix {
public:
int n,m;
vector<vector<int>>pref;
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = n>0 ? matrix[0].size() : 0;
        pref = vector<vector<int>>(n+1, vector<int>(m+1, 0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                pref[i][j]=matrix[i-1][j-1]+pref[i-1][j]+pref[i][j-1]-pref[i-1][j-1] ;
            }
        }
    }
    
    int sumRegion(int a, int b, int c, int d) {
        a++;b++;c++;d++;
        return pref[c][d]-pref[a-1][d]-pref[c][b-1]+pref[a-1][b-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */