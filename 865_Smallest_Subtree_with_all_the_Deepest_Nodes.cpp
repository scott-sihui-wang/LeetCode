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
    void getDepth(TreeNode* node, int d, unordered_map<TreeNode*,int>& depth, int& max_depth){
        if(node==nullptr)return;
        depth[node]=d;
        max_depth=max(max_depth,d);
        getDepth(node->left,d+1,depth,max_depth);
        getDepth(node->right,d+1,depth,max_depth);
    }
    TreeNode* containDeepest(TreeNode* node, unordered_map<TreeNode*,int>& depth, int max_depth){
        if(node==nullptr)return nullptr;
        if(depth[node]==max_depth)return node;
        TreeNode* l=containDeepest(node->left,depth,max_depth);
        TreeNode* r=containDeepest(node->right,depth,max_depth);
        if(l!=nullptr && r!=nullptr){
            return node;
        }
        else if(l!=nullptr){
            return l;
        }
        else if(r!=nullptr){
            return r;
        }
        else{
            return nullptr;
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int max_depth=-1;
        unordered_map<TreeNode*,int>depth;
        getDepth(root,0,depth,max_depth);
        return containDeepest(root,depth,max_depth);
    }
};