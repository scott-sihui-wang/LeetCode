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
    string i2s(int val){
        bool isNeg=false;
        if(val<0){
            isNeg=true;
            val=-val;
        }
        int digits[3];
        int front=2;
        do{
            digits[front--]=val%10;
            val=val/10;
        }while(val!=0);
        if(isNeg){
            string s(3-front,'\0');
            s[0]='-';
            for(int i=1;i<3-front;i++){
                s[i]=digits[front+i]+'0';
            }
            return s;
        }
        else{
            string s(2-front,'\0');
            for(int i=0;i<2-front;i++){
                s[i]=digits[front+i+1]+'0';
            }
            return s;
        }
    }
    void solve(TreeNode* root, vector<string>& sol, int* sub_sol, int idx){
        if(root->left==NULL && root->right==NULL){
            sub_sol[idx]=root->val;
            string s("");
            for(int i=0;i<idx;i++){
                s.append(i2s(sub_sol[i]));
                s.append("->");
            }
            s.append(i2s(sub_sol[idx]));
            sol.push_back(s);
        }
        else{
            sub_sol[idx]=root->val;
            if(root->left!=NULL){
                solve(root->left,sol,sub_sol,idx+1);
            }
            if(root->right!=NULL){
                solve(root->right,sol,sub_sol,idx+1);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sol;
        int sub_sol[100];
        solve(root,sol,sub_sol,0);
        return sol;
    }
};