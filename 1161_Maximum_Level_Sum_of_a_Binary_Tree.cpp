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
    int maxLevelSum(TreeNode* root) {
        TreeNode* node_list[10000];
        node_list[0]=root;
        int max_sum=node_list[0]->val;
        int max_level=1;
        int cur_level=1;
        int left=0;
        int right=1;
        int prev_left;
        int cur_sum;
        while(right>left){
            cur_sum=0;
            cur_level++;
            prev_left=left;
            left=right;
            right=left;
            for(int i=prev_left;i<left;i++){
                if(node_list[i]->left!=NULL){
                    node_list[right++]=node_list[i]->left;
                    cur_sum+=node_list[i]->left->val;
                    
                }
                if(node_list[i]->right!=NULL){
                    node_list[right++]=node_list[i]->right;
                    cur_sum+=node_list[i]->right->val;
                }
            }
            if(right>left && cur_sum>max_sum){
                max_sum=cur_sum;
                max_level=cur_level;
            }
        }
        return max_level;
    }
};