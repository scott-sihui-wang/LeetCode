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
    void traverse(TreeNode* root,TreeNode* parent,bool isRight,int& val){
        if(root==nullptr)return;
        traverse(root->left,root,false,val);
        traverse(root->right,root,true,val);
        if(parent!=nullptr){
            int diff;
            if(root->val>1){
                diff=root->val-1;
                root->val=1;
                parent->val+=diff;
                val+=diff;
            }
            else if(root->val<1){
                diff=1-root->val;
                root->val=1;
                parent->val-=diff;
                val+=diff;
            }
        }
    }
    int distributeCoins(TreeNode* root) {
        int ans=0;
        traverse(root,nullptr,false,ans);
        return ans;
    }
};