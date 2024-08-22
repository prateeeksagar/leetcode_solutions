class Solution {
public:
        // this can be solved using kahn algorithm
        // observation: if you react again on same node then it is a directed cycle graph so return false else true
        // to find cycle detection in directed cycle graph we have to check ans result of kahn algo == no of courses
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // kahn algo: indegree and queue

        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto &it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        vector<int> ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto &it: adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
            
        }
        if(numCourses == ans.size()) return true;
        return false;
    }
};