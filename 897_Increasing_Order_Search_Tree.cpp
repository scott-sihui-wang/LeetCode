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
    void traverse(TreeNode* root, vector<int>& nodes){
        if(root==nullptr)return;
        traverse(root->left,nodes);
        nodes.push_back(root->val);
        traverse(root->right,nodes);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> nodes;
        traverse(root,nodes);
        TreeNode* ans=new TreeNode(nodes[0]);
        TreeNode* prev=ans;
        for(int i=1;i<nodes.size();i++){
            TreeNode* ptr=new TreeNode(nodes[i]);
            prev->right=ptr;
            prev=ptr;
        }
        return ans;
    }
};