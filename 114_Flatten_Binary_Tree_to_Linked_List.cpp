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
    TreeNode* solve(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        else if(root->left==NULL && root->right==NULL){
            return root;
        }
        else{
            if(root->left!=NULL){
                TreeNode* left_head=solve(root->left);
                TreeNode* left_tail=left_head;
                while(left_tail->right!=NULL){
                    left_tail=left_tail->right;
                }
                TreeNode* right_head=solve(root->right);
                root->left=NULL;
                root->right=left_head;
                left_tail->right=right_head;
            }
            else{
                root->right=solve(root->right);
            }
            return root;
        }
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};