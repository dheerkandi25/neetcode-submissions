class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,0);
        lis[n-1]=1;
        int final=1;
        for(int i=n-2;i>=0;i--) {
            int ans=1;
            for(int j=i+1;j<n;j++) {
                if(nums[i]<nums[j]) {
                    ans=max(ans,1+lis[j]);
                }
            }
            lis[i]=ans;
            final=max(final,ans);
        }
        return final;
        
    }
};
