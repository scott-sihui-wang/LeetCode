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
    ListNode* deleteDuplicates(ListNode* head) {
        int cur_val=-101;
        ListNode* ptr=head;
        ListNode* processed=new ListNode(0,head);
        ListNode* recycle=processed;
        bool begin=true;
        while(ptr!=nullptr){
            if(ptr->val>cur_val){
                cur_val=ptr->val;
                ptr=ptr->next;
                if(!begin){
                    processed=processed->next;
                }
                else{
                    begin=false;
                }
            }
            else{
                ptr=ptr->next;
                begin=true;
                if(processed->next==head){
                    head=ptr;
                    processed->next=head;
                }
                else{
                    processed->next=ptr;
                }
            }
        }
        delete recycle;
        return head;
    }
};