class Solution {
private:
    bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node]) {
            if (!vis[it]) {
                if (dfs(it, adj, vis, pathVis)) return true;
            }
            else if (pathVis[it]) {  // back edge → cycle
                return true;
            }
        }

        pathVis[node] = 0; // remove from current path
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];

        for (auto &it : prerequisites) {
            int course = it[0];
            int preq = it[1];
            adj[preq].push_back(course); // prereq → course
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false; // cycle found
            }
        }

        return true; // no cycle
    }
};