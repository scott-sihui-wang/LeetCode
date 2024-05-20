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
    string subtree2str(TreeNode* root){
        if(root==nullptr)return string("()");
        if(root->left==nullptr && root->right==nullptr) return string("("+to_string(root->val)+")");
        if(root->right==nullptr){
            return string("("+to_string(root->val)+subtree2str(root->left)+")");
        }
        return string("("+to_string(root->val)+subtree2str(root->left)+subtree2str(root->right)+")");
    }
    string tree2str(TreeNode* root) {
        if(root->right!=nullptr){
            return string(to_string(root->val)+subtree2str(root->left)+subtree2str(root->right));
        }
        else if(root->left!=nullptr){
            return string(to_string(root->val)+subtree2str(root->left));
        }
        else{
            return string(to_string(root->val));
        }
    }
};