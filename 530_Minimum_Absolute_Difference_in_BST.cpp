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
    vector<int> inOrder;
    int diff=INT_MAX;
    void inOrderTraversal(TreeNode* ptr){
        if(ptr==nullptr)return;
        inOrderTraversal(ptr->left);
        inOrder.push_back(ptr->val);
        if(inOrder.size()>=2){
            if(inOrder[inOrder.size()-1]-inOrder[inOrder.size()-2]<diff){
                diff=inOrder[inOrder.size()-1]-inOrder[inOrder.size()-2];
            }
        }
        inOrderTraversal(ptr->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inOrderTraversal(root);
        return diff;
    }
};