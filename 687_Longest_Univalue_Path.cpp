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
    int solve(TreeNode* root,int& cnt){
        if(root==NULL){
            return 0;
        }
        else{
            int l=solve(root->left,cnt);
            int r=solve(root->right,cnt);
            int sol_l,sol_r,sol_a;
            if(root->left!=NULL && root->left->val==root->val){
                sol_l=l+1;
            }
            else{
                sol_l=1;
            }
            if(root->right!=NULL && root->right->val==root->val){
                sol_r=r+1;
            }
            else{
                sol_r=1;
            }
            if(root->left!=NULL && root->right!=NULL && root->val==root->left->val && root->val==root->right->val){
                sol_a=l+r+1;
            }
            else{
                sol_a=1;
            }
            cnt=max(cnt,max(sol_a,max(sol_l,sol_r)))            ;
            return max(sol_l,sol_r);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        else{
            int cnt=0;
            solve(root,cnt);
            return cnt-1;
        }
    }
};