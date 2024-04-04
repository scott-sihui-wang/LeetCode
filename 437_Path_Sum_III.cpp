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
    vector<long long> solve(TreeNode* root, int& cnt, int targetSum){
        if(root==NULL){
            vector<long long> tmp;
            return tmp;
        }
        else{
            if(root->val==targetSum){
                ++cnt;
            }
            vector<long long> sol_l=solve(root->left,cnt,targetSum);
            vector<long long> sol_r=solve(root->right,cnt,targetSum);
            for(int i=0;i<sol_l.size();i++){
                sol_l[i]+=root->val;
                if(sol_l[i]==targetSum){
                    ++cnt;
                }
            }
            for(int i=0;i<sol_r.size();i++){
                sol_r[i]+=root->val;
                if(sol_r[i]==targetSum){
                    ++cnt;
                }
            }
            vector<long long>sol;
            sol.push_back(root->val);
            sol.insert(sol.end(),sol_l.begin(),sol_l.end());
            sol.insert(sol.end(),sol_r.begin(),sol_r.end());
            return sol;
        }
    }
    int pathSum(TreeNode* root, int targetSum) {
        int cnt=0;
        solve(root,cnt,targetSum);
        return cnt;
    }
};