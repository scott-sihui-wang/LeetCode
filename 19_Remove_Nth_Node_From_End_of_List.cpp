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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* result=head;
        ListNode* ptr=head;
        ListNode* trace[30];
        int top=-1;
        while(ptr!=NULL){
            trace[++top]=ptr;
            ptr=ptr->next;
        }
        if(top+1-n==0){
            result=result->next;
        }
        else if(n==1){
            trace[top-1]->next=NULL;
        }
        else if(top-n>=0){
            trace[top-n]->next=trace[top+2-n];
        }
        return result;
    }
};