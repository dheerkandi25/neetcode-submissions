class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int i,int amount,vector<int>&coins){
        if(i>=coins.size() || amount<0) {
            return 0;
        }
        else if(amount==0) {
            return 1;
        }
        if(dp[i][amount]!=-1) {
            return dp[i][amount];
        }
        return dp[i][amount]=dfs(i,amount-coins[i],coins)+dfs(i+1,amount,coins);
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return dfs(0,amount,coins);

        
    }
};
