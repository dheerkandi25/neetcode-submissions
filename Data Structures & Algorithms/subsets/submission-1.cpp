class Solution {
public:
    vector<vector<int>>ans;
    void getSubsets(vector<int>&nums,int i,vector<int>&curr) {
        if(i==nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        getSubsets(nums,i+1,curr);
        curr.pop_back();
        getSubsets(nums,i+1,curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        getSubsets(nums,0,curr);
        return ans;
        
    }
};
