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
    void traverse(TreeNode* node,vector<int>& vals,vector<int>& mistake,vector<TreeNode*>& position){
        if(node!=nullptr){
            traverse(node->left,vals,mistake,position);
            vals.push_back(node->val);
            position.push_back(node);
            int sz=vals.size();
            if(sz>1 && vals[sz-1]<vals[sz-2]){
                mistake.push_back(sz-2);
                mistake.push_back(sz-1);
            }
            traverse(node->right,vals,mistake,position);
        }
    }
    void recoverTree(TreeNode* root) {
        vector<int> vals;
        vector<int> mistake;
        vector<TreeNode*> position;
        traverse(root,vals,mistake,position);
        int v1=vals[mistake[0]],v2=vals[mistake[mistake.size()-1]];
        position[mistake[0]]->val=v2;
        position[mistake[mistake.size()-1]]->val=v1;
    }
};