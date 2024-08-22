class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // i can solve this problem using bfs kahn algorithm (topo sort)


        // creating adjaceny list
        vector<int> adj[numCourses]; // O(V+E)
        vector<int> indegrees(numCourses, 0); // O(numCourses)
        
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegrees[u]++;
        }

        queue<int> q; //O(numCourses)
        for(int i = 0 ; i < numCourses; i++) {
            if(indegrees[i] == 0) q.push(i);
        }

        vector<int> ans; // O(N)
        while(!q.empty()) { // O(V+E)
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &it: adj[node]) {
                indegrees[it]--;
                if(indegrees[it] == 0) {
                    q.push(it);
                }
            }
        }

        if(ans.size() == numCourses) return ans;
        return {};


    }
};