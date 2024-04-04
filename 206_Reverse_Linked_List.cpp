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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        int val[5000];
        int cnt=0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            val[cnt++]=ptr->val;
            ptr=ptr->next;
        }
        ptr=head;
        int i=0;
        while(ptr!=NULL){
            ptr->val=val[cnt-1-i];
            i++;
            ptr=ptr->next;
        }
        return head;
    }
};