/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenBranch(Node* ptr1,Node* ptr2){
        stack<Node*> s;
        while(ptr2!=nullptr){
            ptr1->next=ptr2;
            ptr1->child=nullptr;
            ptr2->prev=ptr1;
            ptr1=ptr1->next;
            if(ptr2->child!=nullptr){
                s.push(ptr2->next);
                ptr2=ptr2->child;
            }
            else{
                ptr2=ptr2->next;
            }
        }
        while(!s.empty()){
            Node* ptr2=s.top();
            s.pop();
            if(ptr2!=nullptr){
                ptr1=flattenBranch(ptr1,ptr2);
            }
        }
        return ptr1;
    }
    Node* flatten(Node* head) {
        if(head==nullptr)return head;
        Node *ptr=head,*nxt=head->next,*ch=head->child;
        ptr=flattenBranch(ptr,ch);
        flattenBranch(ptr,nxt);
        return head;
    }
};