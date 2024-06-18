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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>>dict;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        int level=0;
        dict[0].push_back({level,root->val});
        while(!q.empty()){
            int sz=q.size();
            level++;
            for(int i=0;i<sz;i++){
                pair p=q.front();
                q.pop();
                if(p.first->left!=nullptr){
                    q.push({p.first->left,p.second-1});
                    dict[p.second-1].push_back({level,p.first->left->val});
                }
                if(p.first->right!=nullptr){
                    q.push({p.first->right,p.second+1});
                    dict[p.second+1].push_back({level,p.first->right->val});
                }
            }
        }
        vector<vector<int>>ans;
        for(auto iter=dict.begin();iter!=dict.end();iter++){
            sort(iter->second.begin(),iter->second.end());
            vector<int>indices;
            for(int i=0;i<iter->second.size();i++){
                indices.push_back(iter->second[i].second);
            }
            ans.push_back(indices);
        }
        return ans;
    }
};