class Solution {
public:

    int count(string s,int a,int b) {
        int ans=0;
        while(a>=0 && b<s.length() && s[a]==s[b]) {
            ans++;
            a--;
            b++;
        }
        return ans;
    }
    int countSubstrings(string s) {
        int ans=0;
        for(int i=0;i<s.length()-1;i++) {
            ans+=count(s,i,i);
            ans+=count(s,i,i+1);
        }
        return ans+1;

        
    }
};
