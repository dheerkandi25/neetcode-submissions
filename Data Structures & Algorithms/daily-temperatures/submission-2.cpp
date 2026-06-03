class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>stk;
        int n=temperatures.size();
        vector<int>ans(n,0);
        ans[n-1]=0;
        stk.push({temperatures[n-1],n-1});
        for(int i=n-2;i>=0;i--) {
            while(!stk.empty() && stk.top().first<=temperatures[i]) {
                stk.pop();
            }
            if(stk.empty()) {
                ans[i]=0;
            }
            else {
                ans[i]=stk.top().second-i;
            }
            stk.push({temperatures[i],i});
        }
        return ans;
    }
};
