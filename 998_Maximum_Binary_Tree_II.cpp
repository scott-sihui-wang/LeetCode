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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(val>root->val){
            TreeNode* sol=new TreeNode(val);
            sol->left=root;
            return sol;
        }
        else{
            TreeNode* ptr1=root;
            TreeNode* ptr2=root->right;
            while(ptr2!=NULL && val<ptr2->val){
                ptr1=ptr1->right;
                ptr2=ptr2->right;
            }
            TreeNode* sol=new TreeNode(val);
            ptr1->right=sol;
            sol->left=ptr2;
            return root;
        }
    }
};