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
    string genStr(TreeNode* root,unordered_map<string,int>& freq,vector<TreeNode*>& ans){
        if(root==nullptr)return string("#");
        string node_str=string(to_string(root->val)+","+genStr(root->left,freq,ans)+","+genStr(root->right,freq,ans));
        freq[node_str]++;
        if(freq[node_str]==2){
            ans.push_back(root);
        }
        return node_str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>freq;
        vector<TreeNode*>ans;
        genStr(root,freq,ans);
        return ans;
    }
};