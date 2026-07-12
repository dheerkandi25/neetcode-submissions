class Solution {
public:
    int integerBreak(int n) {
        vector<int>dp(n+1,0);

        for(int curr=2;curr<=n;curr++) {
            for(int i=1;i<curr;i++) {
                int remaining=curr-i;
                dp[curr]=max(dp[curr],i*max(remaining,dp[remaining]));
            }
        }
        return dp[n];

        
    }
};