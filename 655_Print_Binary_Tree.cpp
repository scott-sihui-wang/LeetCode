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
    void print(TreeNode* root,vector<vector<string>>& ans,int x,int y){
        if(root==nullptr)return;
        ans[x][y]=to_string(root->val);
        if(root->left!=nullptr){
            print(root->left,ans,x+1,y-(1<<(ans.size()-x-2)));
        }
        if(root->right!=nullptr){
            print(root->right,ans,x+1,y+(1<<(ans.size()-x-2)));
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int m=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* p=q.front();
                q.pop();
                if(p->left!=nullptr){
                    q.push(p->left);
                }
                if(p->right!=nullptr){
                    q.push(p->right);
                }
            }
            m++;
        }
        int n=(1<<m)-1;
        vector<vector<string>>ans(m,vector<string>(n,""));
        print(root,ans,0,(n-1)/2);
        return ans;
    }
};