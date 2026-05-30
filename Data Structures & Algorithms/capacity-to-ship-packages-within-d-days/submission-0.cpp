class Solution {
public:
    int countDays(vector<int>&weights,int cap) {
        int curr=0;
        int days=1;
        for(int w:weights) {
            if(curr+w>cap) {
                curr=w;
                days++;
            }
            else{
                curr+=w;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=INT_MIN;
        int right=0;
        for(int w:weights) {
            right+=w;
            left=max(left,w);
        }
        int ans=right;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(countDays(weights,mid)<=days) {
                ans=min(ans,mid);
                right=mid-1;
            } else {
                left=mid+1;
            }
        }
        return ans;

        
    }
};