class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]++;
        }
        vector<int>ans;
        set<int>set;
        int curr=0;
        for(int i=0;i<s.length();i++) {
            mp[s[i]]--;
            curr++;
            if(set.find(s[i])==set.end()) {
                set.insert(s[i]);
            }
            if(mp[s[i]]==0) {
                set.erase(s[i]);
                if(set.empty()){
                    ans.push_back(curr);
                    curr=0;
                }
            }
        }
        return ans;
        
    }
};
