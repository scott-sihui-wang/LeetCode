/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void distKInSubTree(TreeNode* node, int k, int depth, vector<int>& ans){
        if(node==nullptr)return;
        if(depth==k){
            ans.push_back(node->val);
            return;
        }
        else if(depth<k){
            distKInSubTree(node->left,k,depth+1,ans);
            distKInSubTree(node->right,k,depth+1,ans);
        }
    }
    void findParents(TreeNode* root, unordered_map<TreeNode*,pair<TreeNode*,int>>& mp){
        if(root==nullptr)return;
        if(root->left!=nullptr){
            mp[root->left]={root,-1};
            findParents(root->left,mp);
        }
        if(root->right!=nullptr){
            mp[root->right]={root,1};
            findParents(root->right,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,pair<TreeNode*,int>> mp;
        vector<int> ans;
        findParents(root,mp);
        if(target==root){
            distKInSubTree(root,k,0,ans);
            return ans;
        }
        else{
            distKInSubTree(target,k,0,ans);
            TreeNode* par=mp[target].first;
            int dir=mp[target].second;
            k--;
            while(k>0 && par!=root){
                distKInSubTree(dir==1?par->left:par->right,k-1,0,ans);
                k--;
                dir=mp[par].second;
                par=mp[par].first;
            }
            if(k>0){
                distKInSubTree(dir==1?par->left:par->right,k-1,0,ans);
            }
            else if(k==0){
                distKInSubTree(par,0,0,ans);
            }
            return ans;
        }
    }
};