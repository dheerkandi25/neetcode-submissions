class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int lastEle=-101;
        int k=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]!=lastEle) {
                lastEle=nums[i];
                swap(nums[k],nums[i]);
                k++;
            }
        }
        return k;
    }
};