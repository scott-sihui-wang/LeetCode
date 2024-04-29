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
    bool compare(TreeNode* root,int v){
        if(root==nullptr)return true;
        if(root->val!=v){
            return false;
        }
        else{
            return compare(root->left,v) && compare(root->right,v);
        }
    }
    bool isUnivalTree(TreeNode* root) {
        int v=root->val;
        return compare(root,v);
    }
};