class Solution {
public:
    bool isTree(vector<vector<int>>adj,vector<int>&vis,int i,int p) {
        if(vis[i]==1) {
            return false;
        }
        vis[i]=1;
        for(int v:adj[i]){
            if(v==p) continue;
            if(!isTree(adj,vis,v,i)) {
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i:edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        if(!isTree(adj,vis,0,-1)){
            return false;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]) return false;
        }
        return true;
    }
};
