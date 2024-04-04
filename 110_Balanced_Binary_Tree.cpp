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
    int height(TreeNode* root, bool& balanced){
        if(root==NULL){
            return 0;
        }
        int h_left=height(root->left,balanced);
        int h_right=height(root->right,balanced);
        if(abs(h_left-h_right)>1){
            balanced=false;
        }
        return 1+max(h_left,h_right);
    }
    bool isBalanced(TreeNode* root) {
        bool balanced=true;
        height(root,balanced);
        return balanced;
    }
};