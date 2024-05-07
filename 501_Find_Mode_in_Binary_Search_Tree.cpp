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
    void traverse(TreeNode* root,unordered_map<int,int>& freq){
        if(root==nullptr)return;
        if(freq.find(root->val)==freq.end()){
            freq[root->val]=1;
        }
        else{
            freq[root->val]++;
        }
        traverse(root->left,freq);
        traverse(root->right,freq);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>freq;
        traverse(root,freq);
        int max_freq=-1;
        unordered_map<int,int>::iterator iter;
        for(iter=freq.begin();iter!=freq.end();iter++){
            max_freq=max(max_freq,iter->second);
        }
        vector<int>ans;
        for(iter=freq.begin();iter!=freq.end();iter++){
            if(iter->second==max_freq){
                ans.push_back(iter->first);
            }
        }
        return ans;
    }
};