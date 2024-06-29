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
    void getArr(TreeNode* node, vector<int>& arr){
        if(node==nullptr)return;
        if(node->left==nullptr && node->right==nullptr){
            arr.push_back(node->val);
            return;
        }
        getArr(node->left,arr);
        arr.push_back(node->val);
        getArr(node->right,arr);
    }
    TreeNode* buildTree(vector<int>& arr, int left, int right){
        if(left>right){
            return nullptr;
        }
        int mid=(left+right)/2;
        TreeNode* node=new TreeNode(arr[mid]);
        node->left=buildTree(arr,left,mid-1);
        node->right=buildTree(arr,mid+1,right);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>arr;
        getArr(root,arr);
        return buildTree(arr,0,arr.size()-1);
    }
};