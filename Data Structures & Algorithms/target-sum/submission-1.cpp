class Solution {
public:
    vector<vector<int>>dp;
    int offset;
    int dfs(int i,int target,vector<int>nums) {
        if (abs(target) > offset) {
            return 0;
        }
        if(i>=nums.size()) {
            if(target==0) {
                return 1;
            }
            else {
                return 0;
            }
        }
        int index=target+offset;
        if(dp[i][index]!=-1) {
            return dp[i][index];
        }
        return dp[i][index] = dfs(i+1,target-nums[i],nums)+dfs(i+1,target+nums[i],nums);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(abs(target)>totalSum)
        return 0;
        offset=totalSum;
        int n=nums.size();
        dp.resize(n,vector<int>(2*totalSum+1,-1));
        return dfs(0,target,nums);

        
    }
};
