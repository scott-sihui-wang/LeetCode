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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr)return head;
        ListNode *LT=NULL,*GE=NULL;
        ListNode *LT_head=NULL,*GE_head=NULL;
        while(head!=nullptr){
            if(head->val<x){
                if(LT==NULL){
                    LT=new ListNode(head->val);
                    LT_head=LT;
                }
                else{
                    LT->next=new ListNode(head->val);
                    LT=LT->next;
                }
            }
            else{
                if(GE==NULL){
                    GE=new ListNode(head->val);
                    GE_head=GE;
                }
                else{
                    GE->next=new ListNode(head->val);
                    GE=GE->next;
                }
            }
            head=head->next;
        }
        if(LT_head!=NULL){
            LT->next=GE_head;
            return LT_head;
        }
        else{
            return GE_head;
        }
    }
};