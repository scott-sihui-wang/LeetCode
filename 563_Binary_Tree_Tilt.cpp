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
    int inOrder(TreeNode* root,int& tilt){
        if(root==nullptr)return 0;
        int sum_left=inOrder(root->left,tilt);
        int sum_right=inOrder(root->right,tilt);
        tilt+=abs(sum_left-sum_right);
        return root->val+sum_left+sum_right;
    }
    int findTilt(TreeNode* root) {
        int tilt=0;
        inOrder(root,tilt);
        return tilt;
    }
};