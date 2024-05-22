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
    void traverse(TreeNode* root, set<int>& vals){
        if(root==nullptr)return;
        vals.insert(root->val);
        traverse(root->left,vals);
        traverse(root->right,vals);
    }
    int findSecondMinimumValue(TreeNode* root) {
        set<int> vals;
        traverse(root,vals);
        if(vals.size()<2)return -1;
        set<int>::iterator iter=vals.begin();
        iter++;
        return *(iter);
    }
};