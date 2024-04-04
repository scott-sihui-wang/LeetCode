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
            preOrder(root->left,node_val);
            node_val.push_back(root->val);
            preOrder(root->right,node_val);
        }
    }
    bool isValidBST(TreeNode* root) {
        vector<int> node_val;
        preOrder(root,node_val);
        int len=node_val.size();
        for(int i=0;i<len-1;i++){
            if(node_val[i+1]<=node_val[i]){
                return false;
            }
        }
        return true;
    }
};