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
    TreeNode* delete_left(TreeNode* node, int val){
        if(node==nullptr)return nullptr;
        if(node->val==val){
            node->left=nullptr;
            return node;
        }
        else if(node->val<val){
            return delete_left(node->right,val);
        }
        else{
            node->left=delete_left(node->left,val);
            return node;
        }
    }
    TreeNode* delete_right(TreeNode* node, int val){
        if(node==nullptr)return nullptr;
        if(node->val==val){
            node->right=nullptr;
            return node;
        }
        else if(node->val>val){
            return delete_right(node->left,val);
        }
        else{
            node->right=delete_right(node->right,val);
            return node;
        }
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* ptr=delete_left(root,low);
        return delete_right(ptr,high);
    }
};