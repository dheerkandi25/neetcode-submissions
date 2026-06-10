class Solution {
public:
    void dfs(vector<vector<int>>adj,vector<int>&vis,int node,int parent){
        if(vis[node]==1)
        return;
        vis[node]=1;
        for(auto i:adj[node]) {
            if(i==parent) continue;
            dfs(adj,vis,i,node);
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        int ans=0;
        for(int i=0;i<n;i++) {
            if(vis[i]==0) {
                ans++;
                dfs(adj,vis,i,-1);
            }
        }
        return ans;


    }
};
