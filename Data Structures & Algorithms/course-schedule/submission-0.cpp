class Solution {
public:
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state) {
        if (state[course] == 1) return true;   // cycle found
        if (state[course] == 2) return false;  // already checked

        state[course] = 1; // visiting

        for (int next : graph[course]) {
            if (dfs(next, graph, state)) {
                return true;
            }
        }

        state[course] = 2; // done
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);

        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];

            // b must be taken before a
            graph[b].push_back(a);
        }

        vector<int> state(numCourses, 0);
        // 0 = unvisited, 1 = visiting, 2 = visited

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0) {
                if (dfs(i, graph, state)) {
                    return false; // cycle exists
                }
            }
        }

        return true;
        
    }
};
