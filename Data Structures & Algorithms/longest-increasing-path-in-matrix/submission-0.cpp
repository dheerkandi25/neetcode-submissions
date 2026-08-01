class Solution {
public:
    vector<vector<int>> directions={{-1,0},{0,-1},{1,0},{0,1}};
    vector<vector<int>>dp;
    int dfs(vector<vector<int>>&matrix,int i,int j,int prevVal) {
        if(i<0 || j<0 || i>=matrix.size() || j>=matrix[0].size() || matrix[i][j]<=prevVal ) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int res=1;
        for(auto d:directions) {
            res=max(res,1+dfs(matrix,i+d[0],j+d[1],matrix[i][j]));
        }
        return dp[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        dp.resize(r,vector<int>(c,-1));
        int LIP=0;
        for(int i=0;i<r;i++) {
            for(int j=0;j<c;j++) {
                LIP=max(LIP,dfs(matrix,i,j,INT_MIN));
            }
        }
        return LIP;

        
    }
};
