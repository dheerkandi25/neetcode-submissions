class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int i,int j,string s1,string s2,string s3){
        if(i==s1.length() && j==s2.length()) {
            return 1;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        if(i<s1.length() && s1[i]==s3[i+j] && dfs(i+1,j,s1,s2,s3)==1) {
            return dp[i][j]=1;
        }
        if(j<s2.length() && s2[j]==s3[i+j] && dfs(i,j+1,s1,s2,s3)==1) {
            return dp[i][j]=1;
        }
        return dp[i][j]=0;
        
        
    }
     bool isInterleave(string s1, string s2, string s3) {
        dp.resize(s1.length()+1,vector<int>(s2.length()+1,-1));
        if(s1.length()+s2.length()!=s3.length()) {
            return false;
        }
        if(dfs(0,0,s1,s2,s3)==1) {
            return true;
        }
        else {
            return false;
        }

        
        
    }
};
