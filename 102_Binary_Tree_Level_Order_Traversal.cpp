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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int> > sol;
        if(root==NULL){
            return sol;
        }
        TreeNode* node_list[2000];
        int left=0;
        int right=1;
        int prev_left;
        node_list[0]=root;
        while(left<right){
            vector<int> sol_level;
            for(int i=left;i<right;i++){
                sol_level.push_back(node_list[i]->val);
            }
            sol.push_back(sol_level);
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
        }
        return sol;
    }
};