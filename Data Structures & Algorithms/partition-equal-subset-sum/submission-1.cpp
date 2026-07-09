class Solution {
public:
    int total;
    vector<vector<int>> dp;

    bool solve(vector<int>& nums, int i, int sum1) {
        if (i == nums.size()) {
            return sum1 == total - sum1;
        }

        if (dp[i][sum1] != -1) {
            return dp[i][sum1];
        }

        bool takeInSum1 = solve(nums, i + 1, sum1 + nums[i]);
        bool takeInSum2 = solve(nums, i + 1, sum1);

        return dp[i][sum1] = takeInSum1 || takeInSum2;
    }

    bool canPartition(vector<int>& nums) {
        total = 0;
        for (int x : nums) total += x;

        if (total % 2 != 0) return false;

        dp.assign(nums.size(), vector<int>(total + 1, -1));

        return solve(nums, 0, 0);
    }
};