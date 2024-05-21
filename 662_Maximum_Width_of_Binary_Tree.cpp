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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()){
            int sz=q.size();
            int l,r;
            for(int i=0;i<sz;i++){
                pair<TreeNode*,long long> elem=q.front();
                q.pop();
                if(i==0)l=elem.second;
                if(i==sz-1)r=elem.second;
                if(elem.first->left!=nullptr){
                    q.push({elem.first->left,2*(elem.second-l)+1});
                }
                if(elem.first->right!=nullptr){
                    q.push({elem.first->right,2*(elem.second-l)+2});
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};