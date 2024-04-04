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
    int* find(TreeNode* root,int& cnt){
        int* sol=new int[2];
        if(root==NULL){
            sol[0]=0;
            sol[1]=0;
            return sol;
        }
        int* sol_left=find(root->left,cnt);
        int* sol_right=find(root->right,cnt);
        sol[0]=root->val+sol_left[0]+sol_right[0];
        sol[1]=1+sol_left[1]+sol_right[1];
        if(sol[0]/sol[1]==root->val){
            cnt++;
        }
        return sol;
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        find(root,cnt);
        return cnt;
    }
};