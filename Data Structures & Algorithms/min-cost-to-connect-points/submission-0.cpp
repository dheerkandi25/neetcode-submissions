class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;

        int result = 0;

        for (int count = 0; count < n; count++) {

            int curr = -1;

            for (int i = 0; i < n; i++) {
                if (!visited[i] &&
                    (curr == -1 || minDist[i] < minDist[curr])) {

                    curr = i;
                }
            }

            visited[curr] = true;

            result += minDist[curr];

            for (int next = 0; next < n; next++) {

                if (!visited[next]) {

                    int dist =
                        abs(points[curr][0] - points[next][0]) +
                        abs(points[curr][1] - points[next][1]);

                    minDist[next] =
                        min(minDist[next], dist);
                }
            }
        }

        return result;
    }
};