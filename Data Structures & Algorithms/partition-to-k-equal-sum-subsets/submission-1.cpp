class Solution {
public:
    bool partition(vector<int>&nums,int length,vector<int>&subsets,int i) {
        if(i==nums.size()) {
            return true;
        }
        for(int k=0;k<subsets.size();k++) {
            if(nums[i]+subsets[k]<=length) {
                subsets[k]+=nums[i];
                if(partition(nums,length,subsets,i+1)) {
                    return true;
                }
                subsets[k]-=nums[i];
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        vector<int>subsets(k,0);
        int sum=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
        }
        if(sum%k!=0) {
            return false;
        }
        return partition(nums,sum/k,subsets,0);



        
    }
};