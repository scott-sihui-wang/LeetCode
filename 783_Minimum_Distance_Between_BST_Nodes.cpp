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
    int minDistNode(TreeNode* node){
        int dist=100001;
        if(node!=NULL){
            if(node->left!=NULL){
                TreeNode* ptr=node->left;
                while(ptr->right!=NULL){
                    ptr=ptr->right;
                }
                dist=min(abs(ptr->val-node->val),dist);
            }
            if(node->right!=NULL){
                TreeNode* ptr=node->right;
                while(ptr->left!=NULL){
                    ptr=ptr->left;
                    dist=min(node->right->left->val-node->val,dist);
                }
                dist=min(abs(ptr->val-node->val),dist);
            }
            dist=min(minDistNode(node->left),dist);
            dist=min(minDistNode(node->right),dist);
        }
        return dist;
    }
    int minDiffInBST(TreeNode* root) {
        return minDistNode(root);
    }
};