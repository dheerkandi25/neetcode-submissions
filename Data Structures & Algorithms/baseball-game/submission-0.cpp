class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>stk;
        int sum=0;
        for(int i=0;i<operations.size();i++) {
            if(operations[i]=="+") {
                if(!stk.empty() && stk.size()>=2) {
                    int a=stk.top();
                    stk.pop();
                    int b=stk.top();
                    stk.pop();
                    stk.push(b);
                    stk.push(a);
                    stk.push(a+b);
                }
            }
            else if(operations[i]=="C") {
                if(!stk.empty()) {
                    stk.pop();
                }
            }
            else if(operations[i]=="D") {
                if(!stk.empty()) {
                    stk.push(2*stk.top());
                }
            }
            else {
                stk.push(stoi(operations[i]));
            }
        }
        while(!stk.empty()) {
            sum+=stk.top();
            stk.pop();
        }
        return sum;
        
    }
};