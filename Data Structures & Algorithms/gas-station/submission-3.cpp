class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGasRequired=0;
        for(int i=0;i<gas.size();i++) {
            totalGasRequired+=gas[i]-cost[i];
        }
        if(totalGasRequired<0) {
            return -1;
        }
        int ans=0;
        int prefix=0;
        for(int i=0;i<gas.size();i++) {
            prefix+=gas[i]-cost[i];
            if(prefix<0) {
                prefix=0;
                ans=i+1;
            }
           
        }
        return ans;
       
       
        
    }
};
