class Solution {
public:
    vector<vector<int>>dp;
    int countDistinct(string s,string t,int i,int j) {
        if(j==t.length()) {
            return 1;
        }
        if(i==s.length()) {
            return 0;
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int res=0;
        if(s[i]==t[j]) {
            res=countDistinct(s,t,i+1,j+1)+countDistinct(s,t,i+1,j);
        }
        else {
            res=countDistinct(s,t,i+1,j);
        }
        return dp[i][j]=res;

    }
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        dp.resize(n+1,vector<int>(m+1,-1));
        return countDistinct(s,t,0,0);


        
    }
};
