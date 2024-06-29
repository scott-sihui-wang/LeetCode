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
    TreeNode* buildTree(vector<int>& arr,int left,int right){
        if(left>right || left>=arr.size())return nullptr;
        TreeNode* node=new TreeNode(arr[left]);
        int i=left+1;
        while(i<arr.size() && arr[i]<arr[left]){
            i++;
        }
        node->left=buildTree(arr,left+1,i-1);
        node->right=buildTree(arr,i,right);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder,0,preorder.size()-1);
    }
};