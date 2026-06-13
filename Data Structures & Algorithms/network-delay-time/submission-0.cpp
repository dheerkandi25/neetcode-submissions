class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            adj[u].push_back({v, t});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > minheap;

        minheap.push({0, k}); // {time, node}

        while (!minheap.empty()) {
            auto [time, node] = minheap.top();
            minheap.pop();

            if (time > dist[node]) {
                continue;
            }

            for (auto& nei : adj[node]) {
                int nextNode = nei.first;
                int travelTime = nei.second;

                int newTime = time + travelTime;

                if (newTime < dist[nextNode]) {
                    dist[nextNode] = newTime;
                    minheap.push({newTime, nextNode});
                }
            }
        }

        int answer = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};