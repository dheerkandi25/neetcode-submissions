class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        while(columnNumber>0) {
            columnNumber--;
            int curr=columnNumber%26;
            ans+=('A'+curr);
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};