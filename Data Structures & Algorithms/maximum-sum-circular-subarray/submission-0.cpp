class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMax=nums[0];
        int globalMin=nums[0];
        int currMax=0;
        int currMin=0;
        int total=0;
        for(int i=0;i<nums.size();i++) {
            currMax=max(nums[i],currMax+nums[i]);
            currMin=min(nums[i],currMin+nums[i]);
            total+=nums[i];
            globalMax=max(globalMax,currMax);
            globalMin=min(globalMin,currMin);
        }
        if(globalMax>0)
        return max(globalMax,total-globalMin);
        else 
        return globalMax;
        
    }
};