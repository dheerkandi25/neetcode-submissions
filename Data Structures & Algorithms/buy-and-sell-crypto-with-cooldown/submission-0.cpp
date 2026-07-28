class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int i,int state,vector<int>prices){
        if(i>=prices.size()) {
            return 0;
        }
        if(dp[i][state]!=-1) {
            return dp[i][state];
        }
        if(state==0) {
            int buying=dfs(i+1,1,prices)-prices[i];;
            int cooldown=dfs(i+1,0,prices);
            dp[i][state]=max(buying,cooldown);
        }
        else {
            int selling=dfs(i+2,0,prices)+prices[i];
            int cooldown=dfs(i+1,1,prices);
            dp[i][state]=max(selling,cooldown);
        }
        return dp[i][state];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.resize(n,vector<int>(2,-1));
        return dfs(0,0,prices);


        
    }
};
