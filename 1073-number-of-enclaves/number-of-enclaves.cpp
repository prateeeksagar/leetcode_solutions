class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> & grid, vector<vector<int>> & vis, int n, int m, vector<vector<int>> & dir) {
        vis[row][col] = 1;

        for(auto &d : dir) {
            int d_row = row + d[0];
            int d_col = col + d[1];

            if(d_row >= 0 && d_row < n && d_col >= 0 && d_col < m && !vis[d_row][d_col] && grid[d_row][d_col] == 1) {
                dfs(d_row, d_col, grid, vis,n , m , dir);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0 , -1}, {0, 1}};
        vector<vector<int>> vis(n , vector<int>(m ,0));

        // this will cover the columns
        for(int i = 0 ; i < n; i++) {

            if(!vis[i][0] && grid[i][0] == 1)dfs(i, 0, grid, vis, n, m, dir);
            if(!vis[i][m-1] && grid[i][m-1] == 1)dfs(i, m-1, grid, vis, n , m, dir);
        
        }

        // this will cover the rows
        for(int i = 0 ; i < m ;i++) {

            if(!vis[0][i] && grid[0][i] == 1) dfs(0, i, grid, vis, n, m, dir);
            if(!vis[n-1][i] && grid[n-1][i] == 1)dfs(n-1, i , grid, vis, n, m, dir);

        }

        // after this i have visited array with 1 and 1 indicate land which touched the boundary
        int closedLand = 0;
        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    closedLand++;
                }
            }
        }

        return closedLand;
    }
};