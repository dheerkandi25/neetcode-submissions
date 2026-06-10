class Solution {
public:
    bool dfs(vector<vector<int>>adj,vector<int>&vis,int source,int dest) {
        if(vis[source]==1){
            return false;
        }
        if(source==dest)
        return true;
        vis[source]=1;
        for(int i:adj[source]) {
            if(dfs(adj,vis,i,dest)) {
                return true;
            }
        }
        return false;

    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites) {
            adj[it[0]].push_back(it[1]);
        }
        vector<bool>ans;
        for(int i=0;i<queries.size();i++) {
            vector<int> vis(numCourses, 0);
            ans.push_back(dfs(adj,vis,queries[i][0],queries[i][1]));
        }
        return ans;
        
    }
};