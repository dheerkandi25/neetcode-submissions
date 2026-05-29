class Solution {
public:
    vector<pair<int,int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
    int dfs(vector<vector<int>>&grid,int i,int j) {
        int ans=4;
        for(auto it:directions) {
            int nx=it.first+i;
            int ny=it.second+j;
            if(nx<grid.size() && ny<grid[0].size() && nx>=0 && ny>=0){
                if(grid[nx][ny]==1) {
                    ans--;
                }
            }
        }
        return ans;

    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if(grid[i][j]==1) {
                    ans+=dfs(grid,i,j);
                }
            }
        }
        return ans;
        
    }
};