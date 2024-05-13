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
    int traverse(TreeNode* root,unordered_map<TreeNode*,int>& rob_val){
        if(root==nullptr)return 0;
        if(rob_val.find(root)!=rob_val.end())return rob_val[root];
        if(root->left==nullptr && root->right==nullptr){
            rob_val[root]=root->val;
            return rob_val[root];
        }
        traverse(root->left,rob_val);
        traverse(root->right,rob_val);
        int val1=traverse(root->left,rob_val)+traverse(root->right,rob_val);
        int val2=root->val;
        if(root->left!=nullptr){
            val2+=traverse(root->left->left,rob_val)+traverse(root->left->right,rob_val);
        }
        if(root->right!=nullptr){
            val2+=traverse(root->right->left,rob_val)+traverse(root->right->right,rob_val);
        }
        rob_val[root]=max(val1,val2);
        return rob_val[root];
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>rob_val;
        return traverse(root,rob_val);
    }
};