class Solution {
public:
    bool backtrack(int i,vector<int>&matchsticks,vector<int>&sides,int length) {
            if(i==matchsticks.size()) {
                return true;
            }
            for(int j=0;j<4;j++) {
                if(sides[j]+matchsticks[i]<=length) {
                    sides[j]+=matchsticks[i];
                    if(backtrack(i+1,matchsticks,sides,length)) {
                        return true;
                    }
                    sides[j]-=matchsticks[i];
                }
            }
            return false;
        }
    bool makesquare(vector<int>& matchsticks) {
        int sum=0;
        for(int i=0;i<matchsticks.size();i++) {
            sum+=matchsticks[i];
        }
        vector<int>sides={0,0,0,0};
        int length=sum/4;
        sort(matchsticks.begin(),matchsticks.end());
        return backtrack(0,matchsticks,sides,length);
        
        


        
    }
};