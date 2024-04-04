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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> >sol;
        if(root==NULL){
            return sol;
        }
        vector<int> *addr[2000];
        TreeNode* node_list[2000];
        node_list[0]=root;
        int level=0;
        int left=0;
        int right=1;
        int prev_left;
        vector<int>* sol_level=new vector<int>();
        sol_level->push_back(root->val);
        addr[level++]=sol_level;
        while(left<right){
            prev_left=left;
            left=right;
            vector<int>* sol_level=new vector<int>();
            for(int i=prev_left;i<left;i++){
                if(node_list[i]->left!=NULL){
                    node_list[right++]=node_list[i]->left;
                    sol_level->push_back(node_list[i]->left->val);
                }
                if(node_list[i]->right!=NULL){
                    node_list[right++]=node_list[i]->right;
                    sol_level->push_back(node_list[i]->right->val);
                }
            }
            if(left<right){
                addr[level++]=sol_level;
            }
        }
        for(int i=level-1;i>=0;i--){
            sol.push_back(*addr[i]);
        }
        return sol;
    }
};