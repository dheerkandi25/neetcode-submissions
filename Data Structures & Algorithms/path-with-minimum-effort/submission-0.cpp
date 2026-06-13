class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minheap;
        minheap.push({0, 0, 0}); // effort, row, col

        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (!minheap.empty()) {
            auto curr = minheap.top();
            minheap.pop();

            int effort = curr[0];
            int r = curr[1];
            int c = curr[2];

            if (r == rows - 1 && c == cols - 1) {
                return effort;
            }

            for (auto dir : directions) {
                int newRow = r + dir[0];
                int newCol = c + dir[1];

                if (newRow < 0 || newCol < 0 || newRow >= rows || newCol >= cols) {
                    continue;
                }

                int diff = abs(heights[newRow][newCol] - heights[r][c]);
                int newEffort = max(effort, diff);

                if (newEffort < dist[newRow][newCol]) {
                    dist[newRow][newCol] = newEffort;
                    minheap.push({newEffort, newRow, newCol});
                }
            }
        }

        return 0;
    }
};