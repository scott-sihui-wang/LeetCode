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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> >sol;
        if(root==NULL){
            return sol;
        }
        bool flag=false;
        TreeNode* node_list[2000];
        int left=0;
        int right=1;
        int prev_left;
        node_list[0]=root;
        vector<int> sol_level;
        sol_level.push_back(root->val);
        sol.push_back(sol_level);
        while(left<right){
            prev_left=left;
            left=right;
            vector<int> sol_level;
            if(flag==false){
                for(int i=left-1;i>=prev_left;i--){
                    if(node_list[i]->right!=NULL){
                        node_list[right++]=node_list[i]->right;
                        sol_level.push_back(node_list[i]->right->val);
                    }
                    if(node_list[i]->left!=NULL){
                        node_list[right++]=node_list[i]->left;
                        sol_level.push_back(node_list[i]->left->val);
                    }
                }
            }
            else if(flag==true){
                for(int i=left-1;i>=prev_left;i--){
                    if(node_list[i]->left!=NULL){
                        node_list[right++]=node_list[i]->left;
                        sol_level.push_back(node_list[i]->left->val);
                    }
                    if(node_list[i]->right!=NULL){
                        node_list[right++]=node_list[i]->right;
                        sol_level.push_back(node_list[i]->right->val);
                    }
                }
            }
            if(left<right){
                sol.push_back(sol_level);
                flag=!flag;
            }
        }
        return sol;
    }
};