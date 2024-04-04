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
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val){
            head=head->next;
        }
        ListNode* ptr=head;
        while(ptr!=NULL){
            ListNode* ptr2=ptr->next;
            while(ptr2!=NULL && ptr2->val==val){
                ptr2=ptr2->next;
            }
            ptr->next=ptr2;
            ptr=ptr->next;
        }
        return head;
    }
};