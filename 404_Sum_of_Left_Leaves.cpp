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
    int sum_left(TreeNode* root, bool isLeft){
        if(root!=nullptr && root->left==nullptr && root->right==nullptr && isLeft){
            return root->val;
        }
        else if(root!=nullptr){
            return sum_left(root->left,true)+sum_left(root->right,false);
        }
        else{
            return 0;
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum_left(root->left,true)+sum_left(root->right,false);
    }
};