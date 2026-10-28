class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        set<pair<int,int>>visit;
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        pq.push({grid[0][0],0,0});
        visit.insert({0,0});
        vector<vector<int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        while(!pq.empty()){
            vector<int>top=pq.top();
            if(top[1]==grid.size()-1 && top[2]==grid[0].size()-1)
            return top[0];
            pq.pop();
            for(int i=0;i<4;i++) {
                int r=top[1]+dir[i][0];
                int c=top[2]+dir[i][1];
                if(r<0 || c<0 || r>=grid.size() || c>=grid[0].size() || visit.find({r,c})!=visit.end()) {
                    continue;
                }
                visit.insert({r,c});
                pq.push({max(grid[r][c],top[0]),r,c});
                
            }
        }
        return grid.size()*grid[0].size();

    }
};
