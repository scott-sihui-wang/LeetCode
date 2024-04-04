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
    TreeNode* solve(vector<int>& nums,int begin,int end){
        if(begin>end)return NULL;
        int max_val=-1;
        int max_idx=-1;
        for(int i=begin;i<=end;i++){
            if(nums[i]>max_val){
                max_val=nums[i];
                max_idx=i;
            }
        }
        TreeNode* sol=new TreeNode(max_val);
        sol->left=solve(nums,begin,max_idx-1);
        sol->right=solve(nums,max_idx+1,end);
        return sol;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len=nums.size();
        return solve(nums,0,len-1);
    }
};