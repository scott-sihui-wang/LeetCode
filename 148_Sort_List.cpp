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
    void Merge(ListNode* head,ListNode* begin,ListNode* r_begin,ListNode* end){
        ListNode* tmp=new ListNode();
        ListNode* ptr=tmp;
        ListNode* ptr_head=begin;
        ListNode *left_ptr=begin,*right_ptr=r_begin;
        while(left_ptr!=r_begin && right_ptr!=end){
            if(left_ptr->val<right_ptr->val){
                tmp->next=new ListNode(left_ptr->val);
                left_ptr=left_ptr->next;
            }
            else{
                tmp->next=new ListNode(right_ptr->val);
                right_ptr=right_ptr->next;
            }
            tmp=tmp->next;
        }
        while(left_ptr!=r_begin){
            tmp->next=new ListNode(left_ptr->val);
            tmp=tmp->next;
            left_ptr=left_ptr->next;
        }
        while(right_ptr!=end){
            tmp->next=new ListNode(right_ptr->val);
            tmp=tmp->next;
            right_ptr=right_ptr->next;
        }
        ptr=ptr->next;
        while(ptr!=nullptr){
            ptr_head->val=ptr->val;
            ptr_head=ptr_head->next;
            ptr=ptr->next;
        }
    }
    void MergeSort(ListNode* head,ListNode* begin,ListNode* end){
        if(begin->next==end)return;
        ListNode* r_begin=begin;
        ListNode* fast_ptr=begin;
        while(fast_ptr!=end){
            fast_ptr=fast_ptr->next;
            if(fast_ptr!=end){
                fast_ptr=fast_ptr->next;
                r_begin=r_begin->next;
            }
        }
        MergeSort(head,begin,r_begin);
        MergeSort(head,r_begin,end);
        Merge(head,begin,r_begin,end);
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr)return head;
        MergeSort(head,head,nullptr);
        return head;           
    }
};