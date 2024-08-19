class Solution {
private:
    bool bfs(int start, vector<int> & vis, vector<vector<int>> & graph) {
        queue<int> q;
        q.push(start);
        int color = 0;
        vis[start] = color;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(auto it: graph[node]) {
                if(vis[it] == -1) {
                    q.push(it);
                    vis[it] = !vis[node];
                } else if(vis[it] == vis[node]) {
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int siz = graph.size();

        vector<int> vis(siz, -1);
        for(int i = 0; i < siz; i++) {
            if(vis[i] == -1) {

                if(bfs(i,vis,graph) == false) {
                    return false;
                }
            }
        }

        return true;

    }
};