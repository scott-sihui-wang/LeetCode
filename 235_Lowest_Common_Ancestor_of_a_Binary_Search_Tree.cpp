/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    //should consider BST's value properties
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ptr=root;
        while(ptr!=NULL){
            if(p->val<ptr->val && q->val<ptr->val){
                ptr=ptr->left;
                return lowestCommonAncestor(ptr,p,q);
            }
            else if(p->val>ptr->val && q->val>ptr->val){
                ptr=ptr->right;
                return lowestCommonAncestor(ptr,p,q);
            }
            else{
                return ptr;
            }
        }
        return NULL;
    }
};