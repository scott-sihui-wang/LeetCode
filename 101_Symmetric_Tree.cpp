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
    bool solve(TreeNode* r1, TreeNode* r2){
        if(r1==NULL && r2==NULL){
            return true;
        }
        else if((r1!=NULL && r2==NULL)||(r1==NULL && r2!=NULL)){
            return false;
        }
        else{
            if(r1->val!=r2->val){
                return false;
            }
            else{
                bool sym1=solve(r1->left,r2->right);
                bool sym2=solve(r1->right,r2->left);
                return (sym1&&sym2);
            }
        }
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left,root->right);
    }
};