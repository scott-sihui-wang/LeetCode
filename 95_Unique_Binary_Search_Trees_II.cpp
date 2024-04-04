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
    vector<TreeNode*> solve(int n, int offset) {
        if(n==0){
            vector<TreeNode*> sol;
            TreeNode* ptr=NULL;
            sol.push_back(ptr);
            return sol;
        }
        else if(n==1){
            vector<TreeNode*> sol;
            TreeNode* ptr=new TreeNode(1+offset);
            sol.push_back(ptr);
            return sol;
        }
        else{
            vector<TreeNode*> sol;
            for(int i=1;i<=n;i++){
                vector<TreeNode*> sol_l=solve(i-1,offset);
                vector<TreeNode*> sol_r=solve(n-i,i+offset);
                for(int j=0;j<sol_l.size();j++){
                    for(int k=0;k<sol_r.size();k++){
                        TreeNode* root=new TreeNode(i+offset,sol_l[j],sol_r[k]);
                        sol.push_back(root);
                    }
                }
            }
            return sol;
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> sol=solve(n,0);
        return sol;
    }
};