class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int j=0;
        int sum=0;
        int ans=INT_MIN;
        while(j<nums.size()) {
            sum+=nums[j];
            ans=max(sum,ans);
            if(sum<0) {
                sum=0;
                i=j+1;
                j=i;
            }
            else
            j++;

        }
        return ans;

    }
};
