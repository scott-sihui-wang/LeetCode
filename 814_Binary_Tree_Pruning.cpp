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
    TreeNode* remove(TreeNode* node){
        if(node==nullptr)return nullptr;
        node->left=remove(node->left);
        node->right=remove(node->right);
        if(node->left==nullptr && node->right==nullptr){
            if(node->val==1){
                return node;
            }
            else{
                return nullptr;
            }
        }
        return node;
    }
    TreeNode* pruneTree(TreeNode* root) {
        return remove(root);
    }
};