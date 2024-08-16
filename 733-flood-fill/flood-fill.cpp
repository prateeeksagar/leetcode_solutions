class Solution {
private:
    // void dfs(int row, int col, vector<vector<int>> & image, vector<vector<int>> & ans, int ini_clr, int n , int m, int color, vector<vector<int>> & dir) {
    //     ans[row][col] = color;

    //     for(int i = 0; i < 4; i++) {
    //         int n_row = row + dir[i][0];
    //         int n_col = col + dir[i][1];

    //         if(n_row >= 0 && n_row < n && n_col >= 0 && n_col < m && image[n_row][n_col] == ini_clr && ans[n_row][n_col] != color) {
    //             dfs(n_row, n_col, image, ans, ini_clr, n , m , color, dir);
    //         } 
    //     }

    // }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        // for dfs function
        // int ini_clr = image[sr][sc];
        // vector<vector<int>>ans = image;
        // vector<vector<int>> dir = {{1,0}, {0, -1}, {-1, 0}, {0,1}};
        // dfs(sr, sc, image, ans, ini_clr, n ,m, color, dir);
        // return ans;

        //for bfs
        queue<pair<int,int>> q;
        vector<vector<int>> ans = image;
        int ini_clr = image[sr][sc];

        q.push({sr,sc});
        ans[sr][sc] = color;
        vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, -1}, {0,1}};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int d_row = row + dir[i][0];
                int d_col = col + dir[i][1];

                if(d_row >= 0 && d_row < n && d_col >= 0 && d_col < m && image[d_row][d_col] == ini_clr && ans[d_row][d_col] != color) {
                    q.push({d_row, d_col});
                    ans[d_row][d_col] = color;
                }
            }   
            
        }
        return ans;
    
    }
};