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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newRoot=new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        else{
            TreeNode* node_list[10000];
            node_list[0]=root;
            int left=0;
            int right=1;
            int prev_left;
            int d=1;
            while(d<depth-1){
                prev_left=left;
                left=right;
                for(int i=prev_left;i<left;i++){
                    if(node_list[i]->left!=NULL){
                        node_list[right++]=node_list[i]->left;
                    }
                    if(node_list[i]->right!=NULL){
                        node_list[right++]=node_list[i]->right;
                    }
                }
                d++;
            }
            for(int i=left;i<right;i++){
                TreeNode* l=node_list[i]->left;
                TreeNode* r=node_list[i]->right;
                node_list[i]->left=new TreeNode(val);
                node_list[i]->left->left=l;
                node_list[i]->right=new TreeNode(val);
                node_list[i]->right->right=r;
            }
            return root;
        }
    }
};