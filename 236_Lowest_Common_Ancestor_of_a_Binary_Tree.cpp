/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int,TreeNode*> solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==NULL){
            return make_pair(0,root);
        }
        else{
            pair<int,TreeNode*> l=solve(root->left,p,q);
            pair<int,TreeNode*> r=solve(root->right,p,q);
            if(l.first==3){
                return make_pair(3,l.second);
            }
            else if(r.first==3){
                return make_pair(3,r.second);
            }
            else if(l.first+r.first==3){
                return make_pair(3,root);
            }
            else if(l.first==0 && r.first==0){
                TreeNode* tmp=NULL;
                if(root==p){
                    return make_pair(1,tmp);
                }
                else if(root==q){
                    return make_pair(2,tmp);
                }
                else{
                    return make_pair(0,tmp);
                }
            }
            else if(l.first==1 || r.first==1){
                if(root==q){
                    return make_pair(3,root);
                }
                else{
                    TreeNode* tmp=NULL;
                    return make_pair(1,tmp);
                }
            }
            else{
                if(root==p){
                    return make_pair(3,root);
                }
                else{
                    TreeNode* tmp=NULL;
                    return make_pair(2,tmp);
                }
            }
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<int,TreeNode*>sol=solve(root,p,q);
        return sol.second;
    }
};