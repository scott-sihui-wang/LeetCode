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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        bool isEnd=false;
        while(!q.empty()){
            int sz=q.size();
            level++;
            int cnt=0,first_null=-1;
            int node_id=0;
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front();
                q.pop();
                node_id++;
                if(node->left==nullptr){
                    if(first_null==-1){
                        first_null=node_id;
                    }
                }
                else{
                    q.push(node->left);
                    cnt++;
                }
                node_id++;
                if(node->right==nullptr){
                    if(first_null==-1){
                        first_null=node_id;
                    }
                }
                else{
                    q.push(node->right);
                    cnt++;
                }
            }
            if((first_null==-1 && cnt!=1<<level)|| (first_null!=-1 && cnt-first_null+1!=0)){
                return false;
            }
            if(isEnd==false && cnt<(1<<level)){
                isEnd=true;
            }
            else if(isEnd==true && cnt!=0){
                return false;
            }
        }
        return true;
    }
};