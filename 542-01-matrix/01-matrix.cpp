class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> res(n, vector<int> (m, 0));
        queue<pair<  pair<int,int> , int>> que;
        for(int row = 0 ; row < n ; row++) {
            for(int col = 0; col < m; col++ ) {
                if(mat[row][col] == 0) {
                    que.push({{row, col},0});
                    vis[row][col] = 1;
                }
            }
        }

        vector<vector<int>> dis = {{-1,0}, {0, 1}, {1,0}, {0,-1}};
        while(!que.empty()) {
            int row = que.front().first.first;
            int col = que.front().first.second;
            int step = que.front().second;
            que.pop();

            res[row][col] = step;
            for(int i = 0 ; i < 4; i++) {
                int d_row = row + dis[i][0];
                int d_col = col + dis[i][1];

                if(d_row >= 0 && d_row < n && d_col >= 0 && d_col < m && !vis[d_row][d_col]) {
                    // we will push in queue and mark vis
                    que.push({{d_row, d_col}, step+1});
                    vis[d_row][d_col] = 1;
                }
            }


        }

        return res;
    }
};