class Solution {
public:
    bool isValid(string s) {
        stack<char>stk;
        unordered_map<char,char>mp;
        mp[')']='(';
        mp['}']='{';
        mp[']']='[';
        for(int i=0;i<s.length();i++) {
            if(s[i]=='(' || s[i]=='[' || s[i]=='{') {
                stk.push(s[i]);
            }
            else {
                if(!stk.empty()) {
                    if(stk.top()==mp[s[i]]) {
                        stk.pop();
                    }
                    else{
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }
        if(stk.size()!=0)
        return false;
        return true;
    }
};
