class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0 ; i<n; i++){
            board[i] = s;
        }
        vector<int> leftrow(n,-1),upperdiagonal(2*n - 1,-1),lowerdiagonal(2*n - 1,-1);

        solve(0,board,leftrow,upperdiagonal,lowerdiagonal,ans,n);
        return ans.size();
        
    }
private:
    void solve(int col, vector<string> &board, vector<int> &leftrow,vector<int> &upperdiagonal, vector<int> &lowerdiagonal, vector<vector<string>> &ans,int n){
        if (col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(leftrow[row] == -1 && lowerdiagonal[col + row] == -1 && upperdiagonal[n - 1 + col - row]){
                board[row][col] = 'Q';
                leftrow[row] = 0;
                upperdiagonal[n - 1 + col - row] = 0;
                lowerdiagonal[col + row] = 0;
                solve(col + 1, board,leftrow,upperdiagonal,lowerdiagonal,ans,n);
                board[row][col] = '.';
                leftrow[row] = -1;
                upperdiagonal[n - 1 + col - row] = -1;
                lowerdiagonal[col + row] = -1;

            }
        }
    }
};