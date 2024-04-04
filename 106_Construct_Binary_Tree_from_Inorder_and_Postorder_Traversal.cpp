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
    TreeNode* build(int* inOrder, int* postOrder, int len){
        if(len==0){
            return NULL;
        }
        else if(len==1){
            return new TreeNode(inOrder[0]);
        }
        int root_val=postOrder[len-1];
        int i=0;
        for(;i<len;i++){
            if(inOrder[i]==root_val){
                break;
            }
        }
        TreeNode* root=new TreeNode(inOrder[i]);
        root->left=build(inOrder,postOrder,i);
        root->right=build(inOrder+i+1,postOrder+i,len-1-i);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        int *inOrder=new int[len];
        int *postOrder=new int[len];
        for(int i=0;i<len;i++){
            inOrder[i]=inorder[i];
            postOrder[i]=postorder[i];
        }
        TreeNode* root=build(inOrder,postOrder,len);
        return root;
    }
};