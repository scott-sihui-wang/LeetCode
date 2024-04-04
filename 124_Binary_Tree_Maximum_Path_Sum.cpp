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
public:
    int solve(TreeNode* root,int& max_sum){
        if(root==NULL){
            return 0;
        }
        else{
            int l=solve(root->left,max_sum);
            int r=solve(root->right,max_sum);
            int sol=max(root->val,max(root->val+l,root->val+r));
            max_sum=max(max_sum,max(sol,l+r+root->val));
            return sol;
        }
    }
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;
        solve(root,max_sum);
        return max_sum;
    }
};