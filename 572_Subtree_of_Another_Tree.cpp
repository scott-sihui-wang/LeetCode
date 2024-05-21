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
    bool isIdentical(TreeNode* ptr1, TreeNode* ptr2){
        if(ptr1==nullptr && ptr2==nullptr){
            return true;
        }
        else if(ptr1!=nullptr && ptr2!=nullptr && ptr1->val==ptr2->val){
            return isIdentical(ptr1->left,ptr2->left) && isIdentical(ptr1->right,ptr2->right);
        }
        else{
            return false;
        }
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(isIdentical(root,subRoot))return true;
        if(root!=nullptr){
            if(isSubtree(root->left,subRoot))return true;
            if(isSubtree(root->right,subRoot))return true;
        }
        return false;
    }
};