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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int overflow=0;
        ListNode* root;
        ListNode* head=new ListNode(0,root);
        ListNode* ptr=head;
        while(l1!=NULL || l2!=NULL || overflow!=0){
            int val=0;
            if(l1!=NULL){
                val+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                val+=l2->val;
                l2=l2->next;
            }
            val+=overflow;
            overflow=val/10;
            val=val%10;
            ptr->next=new ListNode(val);
            ptr=ptr->next;
        }
        ptr=head->next;
        delete head;
        return ptr;
    }
};