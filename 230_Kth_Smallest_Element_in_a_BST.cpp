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
    void preOrder(TreeNode* root, vector<int>& node_val){
        if(root==NULL){
            return;
        }
        else{
            preOrder(root->left, node_val);
            node_val.push_back(root->val);
            preOrder(root->right, node_val);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> node_val;
        preOrder(root,node_val);
        return node_val[k-1];
    }
};