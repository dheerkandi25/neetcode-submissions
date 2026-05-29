class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int i=0;i<=k && i<nums.size();i++) {
            mp[nums[i]]++;
            if(mp[nums[i]]>1) {
                return true;
            }
        }
        int left=0;
        int right=k+1;
        while(right<nums.size()) {
            mp[nums[right]]++;
            mp[nums[left]]--;
            if(mp[nums[right]]>1) {
                return true;
            }
            right++;
            left++;


        }
        return false;
        
        
    }
};