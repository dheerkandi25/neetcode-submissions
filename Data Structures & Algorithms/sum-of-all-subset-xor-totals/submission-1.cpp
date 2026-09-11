class Solution {
public:
    int sum;
    void getXOR(vector<int>&nums,int i,int curr) {
        if(i==nums.size()) {
            sum+=curr;
            return;
        }
        curr=curr^nums[i];
        getXOR(nums,i+1,curr);
        curr=curr^nums[i];
        getXOR(nums,i+1,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        sum=0;
        getXOR(nums,0,0);
        return sum;

        
    }
};