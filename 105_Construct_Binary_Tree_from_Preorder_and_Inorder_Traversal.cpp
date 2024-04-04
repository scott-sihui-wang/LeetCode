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
    TreeNode* build(int* preOrder,int* inOrder, int len){
        if(len==0){
            return NULL;
        }
        else if(len==1){
            return new TreeNode(preOrder[0]);
        }
        int i=0;
        for(;i<len;i++){
            if(inOrder[i]==preOrder[0]){
                break;
            }
        }
        TreeNode* root=new TreeNode(preOrder[0]);
        root->left=build(preOrder+1,inOrder,i);
        root->right=build(preOrder+i+1,inOrder+i+1,len-i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=preorder.size();
        int* preOrder=new int[len];
        int* inOrder=new int[len];
        for(int i=0;i<len;i++){
            preOrder[i]=preorder[i];
            inOrder[i]=inorder[i];
        }
        return build(preOrder,inOrder,len);
    }
};