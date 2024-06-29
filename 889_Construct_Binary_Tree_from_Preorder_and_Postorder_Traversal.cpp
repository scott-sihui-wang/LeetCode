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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& postorder, int left1, int right1, int left2, int right2){
        if(left1>right1 || left2>right2)return nullptr;
        TreeNode* node=new TreeNode(preorder[left1]);
        if(left1<right1 && left2<right2){
            int i=left2;
            while(i<right2 && postorder[i]!=preorder[left1+1]){
                i++;
            }
            node->left=buildTree(preorder,postorder,left1+1,left1+1+i-left2,left2,i);
            node->right=buildTree(preorder,postorder,left1+2+i-left2,right1,i+1,right2-1);
        }
        else{
            node->left=nullptr;
            node->right=nullptr;
        }        
        return node;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return buildTree(preorder,postorder,0,preorder.size()-1,0,postorder.size()-1);        
    }
};