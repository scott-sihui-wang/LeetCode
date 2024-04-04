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
    void solve(TreeNode* root, int& sum, int target, bool& solved){
        if(solved==true){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(sum==target){
                solved=true;
            }
        }
        else{
            if(root->left!=NULL){
                sum=sum+root->left->val;
                solve(root->left,sum,target,solved);
                sum=sum-root->left->val;
            }
            if(root->right!=NULL){
                sum=sum+root->right->val;
                solve(root->right,sum,target,solved);
                sum=sum-root->right->val;
            }
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        else{
            bool solved=false;
            int sum=root->val;
            solve(root,sum,targetSum,solved);
            return solved;
        }
    }
};