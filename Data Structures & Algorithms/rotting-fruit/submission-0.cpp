class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int fresh = 0;

        int rows = grid.size();
        int cols = grid[0].size();

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 2) {
                    que.push({i, j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        int minutes = 0;

        while(!que.empty() && fresh > 0) {
            int n = que.size();

            for(int i = 0; i < n; i++) {
                auto p = que.front();
                que.pop();

                for(int j = 0; j < 4; j++) {
                    int x = p.first + dirs[j][0];
                    int y = p.second + dirs[j][1];

                    if(x >= 0 && y >= 0 && x < rows && y < cols && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        que.push({x, y});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
        
    }
};
