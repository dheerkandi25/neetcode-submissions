class Solution {
public:
    vector<vector<int>>dp;
    int minDistance1(string word1,string word2,int i,int j) {
        if(i==word1.length() && j==word2.length()) {
            return 0;
        }
        else if(i==word1.length() || j==word2.length()) {
            int remWord1=word1.length()-i;
            int remWord2=word2.length()-j;
            return abs(remWord1-remWord2);
        }
        if(dp[i][j]!=-1) {
            return dp[i][j];
        }
        int res=INT_MAX;
        if(word1[i]==word2[j]) {
            res=min(res,minDistance1(word1,word2,i+1,j+1));
        }
        else {
            res=min(res,1+min(minDistance1(word1,word2,i,j+1),min(minDistance1(word1,word2,i+1,j),minDistance1(word1,word2,i+1,j+1))));
        }
        return dp[i][j]=res;
    }
    int minDistance(string word1, string word2) {
        dp.resize(word1.length(),vector<int>(word2.length(),-1));
        return minDistance1(word1,word2,0,0);

        
    }
};
