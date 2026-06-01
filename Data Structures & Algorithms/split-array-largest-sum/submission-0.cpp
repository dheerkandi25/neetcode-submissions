class Solution {
public:
    int getSplits(vector<int>&nums,int mid){
        int splits=1;
        int curr=0;
        for(int a:nums) {
            if(curr+a>mid) {
                curr=a;
                splits++;
            }
            else
            curr+=a;
        }
        
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum=0;
        int left=0;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            left=max(left,nums[i]);
        }
        
        int right=sum;
        int ans=0;
        while(left<=right) {
            int mid=left+(right-left)/2;
            int n=getSplits(nums,mid);
            if(n<=k) {
                ans=mid;
                right=mid-1;
            }
            else {
                left=mid+1;
            }
            
        }
        return ans;
        
    }
};