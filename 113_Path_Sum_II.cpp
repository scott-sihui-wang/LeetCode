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
    
    void solve(TreeNode* root, int sum, int targetSum, int* path, int depth, vector<vector<int> >&sol){
        if(root!=NULL){
            sum+=root->val;
            path[depth]=root->val;
            if(root->left==NULL && root->right==NULL){
                if(sum==targetSum){
                    vector<int>sub_sol;
                    for(int i=0;i<=depth;i++){
                        sub_sol.push_back(path[i]);
                    }
                    sol.push_back(sub_sol);
                }
            }
            else{
                if(root->left!=NULL){
                    solve(root->left,sum,targetSum,path,depth+1,sol);
                }
                if(root->right!=NULL){
                    solve(root->right,sum,targetSum,path,depth+1,sol);
                }
            }
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> >sol;
        if(root==NULL){
            return sol;
        }
        else{
            int sum=0;
            int path[5000];
            solve(root,sum,targetSum,path,0,sol);
            return sol;
        }
    }
};