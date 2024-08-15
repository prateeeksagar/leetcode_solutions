class Solution {
private:
    vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0 ,-1}};
    void dfs(int row, int col ,vector<vector<char>>& board, vector<vector<int>> & vis, int n , int m ) {
        // 1. mark visited 2. start for loop for four direction and validate the i, j and not visited then start dfs again
        vis[row][col] = 1;

        for(int i = 0; i < 4; i++) {
            int drow = row + dir[i][0];
            int dcol = col + dir[i][1];

            if(drow >= 0 && drow < n && dcol >= 0 && dcol < m && !vis[drow][dcol] && board[drow][dcol] == 'O') {
                dfs(drow, dcol, board, vis, n , m);
            }
        }
        return;
    }
public:

    void solve(vector<vector<char>>& board) {
        // we are using dfs call for this but we can also use bfs
        // first iterate over the boundary and check for '0' and start the dfs call because
        // only those touched with boundary can be changed
        

        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n,vector<int>(m, 0));
        // rows
        for(int i = 0 ; i < m; i++) {
            if(board[0][i] == 'O' && !vis[0][i]) {
                dfs(0, i, board, vis, n , m);
            } 

            if(board[n-1][i] == 'O' && !vis[n-1][i]) {
                dfs(n-1, i, board, vis, n ,m);
            }
        } 
        // iterate for the columns
        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !vis[i][0]) {
                dfs(i , 0, board, vis, n , m);
            }

            if(board[i][m-1] == 'O' && !vis[i][m-1]) {
                dfs(i, m-1, board, vis, n, m);
            }
        }

        // if the the value is not visited and also it is 'O' then we know it is inside the 'X'
        for(int i = 0;i < n; i++) {
            for(int j = 0 ; j < m ;j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};