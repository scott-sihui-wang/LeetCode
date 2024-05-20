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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1!=nullptr && root2!=nullptr){
            TreeNode* ptr=new TreeNode(root1->val+root2->val);
            ptr->left=mergeTrees(root1->left,root2->left);
            ptr->right=mergeTrees(root1->right,root2->right);
            return ptr;
        }
        else if(root1!=nullptr){
            TreeNode* ptr=new TreeNode(root1->val);
            ptr->left=mergeTrees(root1->left,nullptr);
            ptr->right=mergeTrees(root1->right,nullptr);
            return ptr;
        }
        else if(root2!=nullptr){
            TreeNode* ptr=new TreeNode(root2->val);
            ptr->left=mergeTrees(root2->left,nullptr);
            ptr->right=mergeTrees(root2->right,nullptr);
            return ptr;
        }
        else{
            return nullptr;
        }
    }
};