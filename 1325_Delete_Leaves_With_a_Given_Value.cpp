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
    TreeNode* rm(TreeNode* root,TreeNode* parent,bool isRight,int target){
        if(root==nullptr)return nullptr;
        if(root->left!=nullptr){
            rm(root->left,root,false,target);
        }
        if(root->right!=nullptr){
            rm(root->right,root,true,target);
        }
        if(root->left==nullptr && root->right==nullptr && root->val==target){
            if(parent==nullptr){
                return parent;
            }
            else{
                if(isRight){
                    parent->right=nullptr;
                }
                else{
                    parent->left=nullptr;
                }
            }
        }
        return root;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return rm(root,nullptr,false,target);
    }
};