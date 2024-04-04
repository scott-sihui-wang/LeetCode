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
    TreeNode* build(vector<int>& nums, int begin, int end){
        if(begin==end){
            return new TreeNode(nums[begin]);
        }
        else if(begin>end){
            return NULL;
        }
        int mid=(begin+end)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=build(nums,begin,mid-1);
        root->right=build(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        TreeNode* root=build(nums,0,len-1);
        return root;
    }
};