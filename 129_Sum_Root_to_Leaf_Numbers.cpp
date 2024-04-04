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
    void solve(TreeNode* root,int node_val,int& sum){
        if(root->left==NULL && root->right==NULL){
            node_val=node_val*10+root->val;
            sum+=node_val;
        }
        else{
            if(root->left!=NULL){
                solve(root->left,node_val*10+root->val,sum);
            }
            if(root->right!=NULL){
                solve(root->right,node_val*10+root->val,sum);
            }
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum=0;
        solve(root,0,sum);
        return sum;
    }
};