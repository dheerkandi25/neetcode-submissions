class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0;
        int sum=0;
        int ans=nums.size();
        int flag=false;
        for(int r=0;r<nums.size();r++) {
            sum+=nums[r];
            while(sum>=target) {
                flag=true;
                ans=min(ans,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        if(!flag)
        return 0;
        
        return ans;
        
    }
};