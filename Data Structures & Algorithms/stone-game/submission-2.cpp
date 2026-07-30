class Solution {
public:
    vector<vector<int>>dp;
    int checkAlice(vector<int>&piles,int i,int j) {
       if(i>j) {
        return 0;
       }
       if(dp[i][j]!=-1) {
        return dp[i][j];
       }
       bool even = (j-i+1)%2==0;
       if(even){
        dp[i][j]=max(piles[i]+checkAlice(piles,i+1,j),piles[j]+checkAlice(piles,i,j-1));
       }
       else {
        dp[i][j]=max(checkAlice(piles,i+1,j),checkAlice(piles,i,j-1));
       }
       return dp[i][j];
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        dp.resize(n,vector<int>(n,-1));
        int totalSum=accumulate(piles.begin(),piles.end(),0);
        int aliceMax=checkAlice(piles,0,n-1);
        return aliceMax>totalSum/2;



        
    }
};