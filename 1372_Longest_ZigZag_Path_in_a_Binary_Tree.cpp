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
    void traverse(TreeNode* node, bool isRight, int length, int& ans){
        if(node==nullptr)return;
        ans=max(ans,length);
        traverse(node->left,false,isRight?length+1:1,ans);
        traverse(node->right,true,isRight?1:length+1,ans);
    }
    int longestZigZag(TreeNode* root) {
        int ans=0;
        traverse(root,false,0,ans);
        return ans;
    }
};