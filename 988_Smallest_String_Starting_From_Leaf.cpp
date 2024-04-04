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
    void solve(TreeNode* root,char* seq,char* sol,int depth){
        if(root->left==NULL && root->right==NULL){
            seq[depth]='a'+root->val;
            char* ch=new char[depth+2];
            for(int i=0;i<=depth;i++){
                ch[i]=seq[depth-i];
            }
            ch[depth+1]='\0';
            if(sol[0]=='\0'){
                strcpy(sol,ch);
            }
            else if(strcmp(sol,ch)>0){
                strcpy(sol,ch);
            }
        }
        else{
            if(root->left!=NULL){
                seq[depth]='a'+root->val;
                solve(root->left,seq,sol,depth+1);
            }
            if(root->right!=NULL){
                seq[depth]='a'+root->val;
                solve(root->right,seq,sol,depth+1);
            }
        }
    }
    string smallestFromLeaf(TreeNode* root) {
        char seq[8501];
        char sol[8501];
        sol[0]='\0';
        solve(root,seq,sol,0);
        return string(sol);
    }
};