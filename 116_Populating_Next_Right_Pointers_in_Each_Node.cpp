/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return root;
        }
        Node* node_list[4096];
        node_list[0]=root;
        int left=0;
        int right=1;
        int prev_left;
        while(left<right){
            prev_left=left;
            left=right;
            for(int i=prev_left;i<left;i++){
                if(i==left-1){
                    node_list[i]->next=NULL;
                }
                else{
                    node_list[i]->next=node_list[i+1];
                }
                if(node_list[i]->left!=NULL){
                    node_list[right++]=node_list[i]->left;
                }
                if(node_list[i]->right!=NULL){
                    node_list[right++]=node_list[i]->right;
                }
            }
        }
        return root;
    }
};