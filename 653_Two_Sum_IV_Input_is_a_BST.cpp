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
    void traverse(TreeNode* node, unordered_map<int,int>& dict_node,int& id){
        if(node==nullptr)return;
        dict_node[node->val]=id++;
        traverse(node->left,dict_node,id);
        traverse(node->right,dict_node,id);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>dict_node;
        int id=0;
        traverse(root,dict_node,id);
        for(unordered_map<int,int>::iterator iter=dict_node.begin();iter!=dict_node.end();iter++){
            if(dict_node.find(k-iter->first)!=dict_node.end() && iter->second!=dict_node[k-iter->first]){
                return true;
            }
        }
        return false;
    }
};