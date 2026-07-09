class Solution {
public:
    vector<vector<long long>>dp;
    int getSum(int n,int i) {
        if(n==0) {
            return 0;
        }
        if(n<0 || i*i>n) {
            return INT_MAX-1;
        }
        
        if(dp[i][n]!=-1) {
            return dp[i][n];
        }
        long long include=1+getSum(n-i*i,i);
        long long noInclude=getSum(n,i+1);
        return dp[i][n]=min(include,noInclude);
    }
    int numSquares(int n) {
        dp.assign(n+1,vector<long long>(n+1,-1));
        return getSum(n,1);

    }
};