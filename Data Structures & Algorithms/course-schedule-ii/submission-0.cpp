class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses);

        for(auto &it:prerequisites) {
            indegree[it[0]]++;
            adj[it[1]].push_back(it[0]);
        }

        int finish=0;
        queue<int>que;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) {
                que.push(i);
            }
        }
        vector<int>ans;
        while(!que.empty()) {
            int curr=que.front();
            ans.push_back(curr);
            que.pop();
            finish++;
            for(int a:adj[curr]) {
                indegree[a]--;
                if(indegree[a]==0) {
                    que.push(a);
                }
            }
        }
        if(finish==numCourses) {
            return ans;
        }
        return {};
    }
};
