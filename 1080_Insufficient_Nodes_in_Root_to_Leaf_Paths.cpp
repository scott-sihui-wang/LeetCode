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
    int path(TreeNode*& root, TreeNode*& node_copy, int prev_val){
        if(root==NULL){
            return 0;
        }
        int val;
        if(root->left!=NULL && root->right==NULL){
            node_copy=new TreeNode();
            val=root->val+path(root->left,node_copy->left,prev_val+root->val);
            node_copy->val=val+prev_val;
            return val;
        }
        else if(root->left==NULL && root->right!=NULL){
            node_copy=new TreeNode();
            val=root->val+path(root->right,node_copy->right,prev_val+root->val);
            node_copy->val=val+prev_val;
            return val;
        }
        else if(root->left!=NULL && root->right!=NULL){
            node_copy=new TreeNode();
            val=root->val+max(path(root->left,node_copy->left,prev_val+root->val),path(root->right,node_copy->right,prev_val+root->val));
            node_copy->val=val+prev_val;
            return val;
        }
        else{
            val=root->val;
            node_copy=new TreeNode(val+prev_val);
            return val;
        }
    }
    void trim(TreeNode*& root, TreeNode*& node_copy, int limit){
        if(node_copy->val<limit){
            root=NULL;
        }
        else{
            if(node_copy->left!=NULL){
                trim(root->left,node_copy->left,limit);
            }
            if(node_copy->right!=NULL){
                trim(root->right,node_copy->right,limit);
            }
        }
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* node_val;
        int prev_val=0;
        path(root,node_val,prev_val);
        trim(root,node_val,limit);
        return root;
    }
};