class Solution {
public:
    int checkAlice(vector<int>&piles,int i,int j,bool alice) {
       if(i>j) {
        return 0;
       }
       if(i==j) {
            if(alice) {
                return piles[i];
            }
            else {
                return 0;
            }
       }
       int ans=0;
       if(alice) {
        ans=max(piles[i]+checkAlice(piles,i+1,j,not alice),piles[j]+checkAlice(piles,i,j-1,not alice));
       }
       else {
        ans=max(checkAlice(piles,i+1,j,not alice),checkAlice(piles,i,j-1,not alice));
       }
       return ans;
    }
    bool stoneGame(vector<int>& piles) {
        return true;

        
    }
};