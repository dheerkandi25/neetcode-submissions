class Solution {
public:
    vector<vector<int>>ans;
    void getSum(vector<int>&nums,int i,vector<int>&curr,int target) {
        if(i==nums.size() || target<0) {
            return;
        }
        if(target==0) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        getSum(nums,i,curr,target-nums[i]);
        curr.pop_back();
        getSum(nums,i+1,curr,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>curr;
        getSum(nums,0,curr,target);
        return ans;
        
    }
};
