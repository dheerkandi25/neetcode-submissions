class Solution {
public:
    int lcs(string s1,string s2,int i,int j,vector<vector<int>>&dp) {
        if(i==s1.length() || j==s2.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]) {
            dp[i][j]=1+lcs(s1,s2,i+1,j+1,dp);
        }
        else {
            dp[i][j]=max(lcs(s1,s2,i+1,j,dp),lcs(s1,s2,i,j+1,dp));
        }
        return dp[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return lcs(text1,text2,0,0,dp);


        
    }
};
