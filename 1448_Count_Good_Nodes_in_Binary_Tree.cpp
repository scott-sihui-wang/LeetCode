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
    void cntGoodNodes(TreeNode* node,int path_max,int& cnt){
        if(node==nullptr)return;
        if(node->val>=path_max){
            cnt++;
            cntGoodNodes(node->left,node->val,cnt);
            cntGoodNodes(node->right,node->val,cnt);
        }
        else{
            cntGoodNodes(node->left,path_max,cnt);
            cntGoodNodes(node->right,path_max,cnt);
        } 
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        cntGoodNodes(root,INT_MIN,cnt);
        return cnt;
    }
};