/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* solve(int val[],int begin,int end){
        if(begin>end)return NULL;
        int mid=(begin+end)/2;
        TreeNode* root=new TreeNode(val[mid]);
        root->left=solve(val,begin,mid-1);
        root->right=solve(val,mid+1,end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        int val[20000];
        int top=-1;
        ListNode* ptr=head;
        while(ptr!=NULL){
            val[++top]=ptr->val;
            ptr=ptr->next;
        }
        return solve(val,0,top);
    }
};