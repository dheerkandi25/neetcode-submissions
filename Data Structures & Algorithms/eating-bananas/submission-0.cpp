class Solution {
public:
    int hours(vector<int>&piles,int k) {
        int ans=0;
        for(int pile:piles) {
            ans+=(pile/k+(pile%k!=0?1:0));
        }
        return ans;
    } 
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxBanana=INT_MIN;
        for(int i=0;i<piles.size();i++) {
            maxBanana=max(maxBanana,piles[i]);
        }
        int left=1;
        int right=maxBanana;
        int ans=-1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(hours(piles,mid)<=h) {
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return ans;
        
    }
};
