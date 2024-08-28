class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int,int>>> q;
        int n = grid.size();
        int m = grid[0].size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
        vector<vector<int>> dist(n , vector<int>(m,1e9));
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        q.push({1, {0,0}});
        dist[0][0] = 1;
        int count_min = INT_MAX;
        while(!q.empty()) {
            auto val = q.front();
            int distance = val.first;
            int row = val.second.first;
            int col = val.second.second;
            q.pop();
            for(auto &it: directions) {
                int d_row = row + it.first;
                int d_col = col + it.second;
                if(d_row < n && d_row >= 0 && d_col < n && d_col >= 0 && grid[d_row][d_col] == 0) {
                    if(distance + 1 < dist[d_row][d_col]) {
                        dist[d_row][d_col] = distance + 1;
                        q.push({dist[d_row][d_col], {d_row, d_col}});
                    }

                    if(d_row == n-1 && d_col == n-1) {
                        return dist[d_row][d_col];
                    }
                }
            }
        }
        if(dist[n-1][n-1] == 1e9) return -1;
        return dist[n-1][n-1];
    }
};