class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>stk;
        vector<int>ans;
        for(int ast:asteroids) {
            if(ast>0) {
                stk.push(ast);
            }
            else {
                bool blast=false;
                while(!stk.empty()) {
                    int a=stk.top();
                    stk.pop();
                    if(a>abs(ast)) {
                        stk.push(a);
                        break;
                    }
                    else if(a==abs(ast)) {
                        blast=true;
                        break;
                    }
                }
                if(stk.empty() && !blast) {
                    ans.push_back(ast);
                }
                
            }
        }
        vector<int>ans1;
        while(!stk.empty()) {
            ans1.push_back(stk.top());
            stk.pop();
        }
        reverse(ans1.begin(),ans1.end());
        for(int s:ans1){
            ans.push_back(s);
        }
        return ans;
        
    }
};