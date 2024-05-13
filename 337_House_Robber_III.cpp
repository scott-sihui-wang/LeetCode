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
        if(rob_val.find(root)!=rob_val.end())return rob_val[root];
        if(root->left==nullptr && root->right==nullptr){
            return rob_val[root]=root->val;
        }
        traverse(root->left,rob_val);
        traverse(root->right,rob_val);
        int val1=rob_val[root->left]+rob_val[root->right];
        int val2=root->val;
        if(root->left!=nullptr){
            val2+=rob_val[root->left->left]+rob_val[root->left->right];
        }
        if(root->right!=nullptr){
            val2+=rob_val[root->right->left]+rob_val[root->right->right];
        }
        return rob_val[root]=max(val1,val2);
    }
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,int>rob_val;
        rob_val[nullptr]=0;
        return traverse(root,rob_val);
    }
};