class Solution {
public:
    vector<vector<string>> ans;
    
    bool isvalid(int row, int col, vector<string>& chess)
    {
        for (int i = 0; i < row; i++)
        {
            if (chess[i][col] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        {
            if (chess[i][j] == 'Q')
            {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < chess.size(); i--, j++)
        {
            if (chess[i][j] == 'Q')
            {
                return false;
            }
        }
        return true;
    }
    
    void solve(int row, vector<string>& chess)
    {
        int n = chess.size();
        if (row == n)
        {
            ans.push_back(chess);
            return;
        }
        for (int col = 0; col < n; col++)
        {
            if (isvalid(row, col, chess))
            {
                chess[row][col] = 'Q';
                solve(row + 1, chess);
                chess[row][col] = '.'; // Backtrack
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> chess(n, string(n, '.'));
        solve(0, chess);
        return ans;
    }
};
