/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    int maxSum=INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        
        dfs(root);
        return maxSum;
    }
    int dfs(TreeNode* root) {
        if(root==NULL) {
            return 0;
        }
        int leftMaxSum=max(0,dfs(root->left));
        int rightMaxSum=max(0,dfs(root->right));
        maxSum=max(maxSum,root->val+leftMaxSum+rightMaxSum);
        return root->val + max(leftMaxSum, rightMaxSum);


    }

};
