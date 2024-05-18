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
    int subtreeSum(TreeNode* root,unordered_map<int,int>&freq){
        if(root==nullptr)return 0;
        int l=subtreeSum(root->left,freq);
        int r=subtreeSum(root->right,freq);
        int ans=l+r+root->val;
        freq[ans]++;
        return ans;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>freq;
        unordered_map<int,int>::iterator iter;
        map<int,vector<int>>freq_sorted;
        subtreeSum(root,freq);
        for(iter=freq.begin();iter!=freq.end();iter++){
            freq_sorted[iter->second].push_back(iter->first);
        }
        vector<int>ans;
        auto iter2=freq_sorted.rbegin();
        for(int i=0;i<iter2->second.size();i++){
            ans.push_back(iter2->second[i]);
        }
        return ans;
    }
};