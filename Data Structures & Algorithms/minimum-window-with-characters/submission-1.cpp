class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>tFreq;
        int req=0;
        for(int i=0;i<t.length();i++) {
            tFreq[t[i]]++;
            if(tFreq[t[i]]==1)
            req++;
        }
        unordered_map<char,int>windowFreq;
        int left=0;
        int right=0;
        int formed=0;
        string ans="";
        int minLen=s.length();
        while(right<s.length()) {
            windowFreq[s[right]]++;
            if(windowFreq[s[right]]==tFreq[s[right]])
            formed++;
            while(left<=right && formed==req) {
                if(right-left+1<=minLen)
                {
                    ans=s.substr(left,right-left+1);
                    minLen=right-left+1;
                }
                windowFreq[s[left]]--;
                if(windowFreq[s[left]]<tFreq[s[left]]) {
                    formed--;
                }
                left++;
            }
            right++;
        }
        return ans;
        
    }
};
