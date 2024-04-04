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
    void search(TreeNode* root, int x, int y, int& depth_x, int& depth_y, TreeNode*& parent_x, TreeNode*& parent_y, int depth_cur){
        if(parent_x!=NULL && parent_y!=NULL){
            return;
        }
        if(root->left!=NULL){
            if(root->left->val==x){
                parent_x=root;
                depth_x=depth_cur+1;
            }
            else if(root->left->val==y){
                parent_y=root;
                depth_y=depth_cur+1;
            }
            search(root->left,x,y,depth_x,depth_y,parent_x,parent_y,depth_cur+1);
        }
        if(root->right!=NULL){
            if(root->right->val==x){
                parent_x=root;
                depth_x=depth_cur+1;
            }
            else if(root->right->val==y){
                parent_y=root;
                depth_y=depth_cur+1;
            }
            search(root->right,x,y,depth_x,depth_y,parent_x,parent_y,depth_cur+1);
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y){
            return false;
        }
        int depth_x,depth_y;
        TreeNode* parent_x=NULL;
        TreeNode* parent_y=NULL;
        int depth_cur=1;
        search(root,x,y,depth_x,depth_y,parent_x,parent_y,depth_cur);
        if(depth_x==depth_y && parent_x!=parent_y){
            return true;
        }
        else{
            return false;
        }
    }
};