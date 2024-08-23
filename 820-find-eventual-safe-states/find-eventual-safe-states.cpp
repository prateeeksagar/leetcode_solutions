class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // reverse it and apply topo sort (kahn algo)
        int n = graph.size();
        vector<int> rev_adj[n];
        vector<int> indegree(n, 0);
        for(int i = 0 ; i < n ; i++) {
            for(auto it: graph[i]) {
                rev_adj[it].push_back(i); // it will reverse all the nodes
                indegree[i]++;
            }
        }

        vector<int> ans;
        queue<int> q;
        for(int i = 0 ; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            } 
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);


            for(auto &it: rev_adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0)q.push(it);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};