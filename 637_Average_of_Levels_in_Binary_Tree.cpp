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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sol;
        TreeNode* node_list[10000];
        node_list[0]=root;
        int left=0;
        int right=1;
        int prev_left;
        sol.push_back(1.0*node_list[0]->val);
        while(left<right){
            prev_left=left;
            left=right;
            long long sum=0;
            int cnt=0;
            for(int i=prev_left;i<left;i++){
                if(node_list[i]->left!=NULL){
                    node_list[right++]=node_list[i]->left;
                    sum+=node_list[i]->left->val;
                    cnt++;
                }
                if(node_list[i]->right!=NULL){
                    node_list[right++]=node_list[i]->right;
                    sum+=node_list[i]->right->val;
                    cnt++;
                }
            }
            if(cnt>0){
                sol.push_back(sum*1.0/cnt);
            }
        }
        return sol;
    }
};