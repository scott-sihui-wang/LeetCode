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
    bool compare(TreeNode* node, vector<int>& voyage, int& i, vector<int>& ans){
        if(node==nullptr)return true;
        if(node->val!=voyage[i])return false;
        if(node->left!=nullptr && node->right!=nullptr){
            if(i+1>=voyage.size())return false;
            if(node->left->val!=voyage[i+1]){
                TreeNode* l=node->right;
                TreeNode* r=node->left;
                node->left=l;
                node->right=r;
                ans.push_back(node->val);
            }
        }
        if(node->left!=nullptr){
            i++;
            bool res=compare(node->left,voyage,i,ans);
            if(!res)return false;
        }
        if(node->right!=nullptr){
            i++;
            bool res=compare(node->right,voyage,i,ans);
            if(!res)return false;
        }
        return true;
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
        vector<int> ans;
        int idx=0;
        if(!compare(root,voyage,idx,ans)){
            return {-1};
        }
        return ans;
    }
};