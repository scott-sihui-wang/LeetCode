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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> desc;
        unordered_map<int,bool> isRoot;
        unordered_map<int,TreeNode*>::iterator iter,iter1,iter2;
        for(int i=0;i<descriptions.size();i++){
            isRoot[descriptions[i][1]]=false;
            iter1=desc.find(descriptions[i][0]);
            iter2=desc.find(descriptions[i][1]);
            if(iter1==desc.end()){
                desc[descriptions[i][0]]=new TreeNode(descriptions[i][0]);
                iter1=desc.find(descriptions[i][0]);
            }
            if(iter2==desc.end()){
                desc[descriptions[i][1]]=new TreeNode(descriptions[i][1]);
                iter2=desc.find(descriptions[i][1]);
            }
            if(descriptions[i][2]==1){
                iter1->second->left=iter2->second;
            }
            else if(descriptions[i][2]==0){
                iter1->second->right=iter2->second;
            }
        }
        for(iter=desc.begin();iter!=desc.end();iter++){
            if(isRoot.find(iter->first)==isRoot.end()){
                return iter->second;
            }
        }
        return NULL;
    }
};