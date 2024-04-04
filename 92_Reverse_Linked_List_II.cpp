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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head->next==NULL){
            return head;
        }
        ListNode* ptr_left;
        ListNode* ptr=head;
        int val[right-left+1];
        int idx=1;
        int idx2=0;
        while(ptr!=NULL){
            if(idx==left){
                ptr_left=ptr;
                
            }
            if(idx>=left && idx<=right){
                val[idx2++]=ptr->val;
            }
            if(idx>right){
                break;
            }
            idx++;
            ptr=ptr->next;
        }
        int cnt=0;
        ptr=ptr_left;
        while(cnt<right-left+1){
            ptr->val=val[right-left-cnt];
            cnt++;
            ptr=ptr->next;
        }
        return head;
    }
};