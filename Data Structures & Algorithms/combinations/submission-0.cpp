class Solution {
public:
    vector<vector<int>>ans;
    void getCombination(int n,int k,int i,vector<int>&curr) {
        if(k==0) {
            ans.push_back(curr);
            return;
        }
        if(i>n) {
            return;
        }
        curr.push_back(i);
        getCombination(n,k-1,i+1,curr);
        curr.pop_back();
        getCombination(n,k,i+1,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>curr;
        getCombination(n,k,1,curr);
        return ans;
    }
};