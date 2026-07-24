class Solution {
public:
    vector<vector<int>>memo;
    int countPaths(int i,int j,int m,int n,vector<vector<int>>&grid) {
        if(i==m || j==n ||grid[i][j]==1) {
            return 0;
        }
        if(i==m-1 && j==n-1) {
            return 1;
        }
        if(memo[i][j]!=-1) {
            return memo[i][j];
        }
        return memo[i][j]=countPaths(i+1,j,m,n,grid)+countPaths(i,j+1,m,n,grid);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memo.resize(m,vector<int>(n,-1));
        return countPaths(0,0,m,n,obstacleGrid);
        
    }
};