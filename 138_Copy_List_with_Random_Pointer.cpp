/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* node[1000];
        unordered_map<Node*,int> dict;
        unordered_map<Node*,int>::iterator iter;
        int top=-1;
        Node* head_copy=new Node(0);
        Node* ptr=head;
        Node* ptr_copy=head_copy;
        while(ptr!=NULL){
            dict[ptr]=++top;
            ptr_copy->next=new Node(ptr->val);
            ptr=ptr->next;
            ptr_copy=ptr_copy->next;
            node[top]=ptr_copy;
        }
        ptr=head;
        ptr_copy=head_copy->next;
        while(ptr!=NULL){
            iter=dict.find(ptr->random);
            if(iter==dict.end()){
                ptr_copy->random=NULL;
            }
            else{
                ptr_copy->random=node[dict[ptr->random]];
            }
            ptr_copy=ptr_copy->next;
            ptr=ptr->next;
        }
        return head_copy->next;
    }
};