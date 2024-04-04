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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0){
            return head;
        }
        int val[500];
        int cnt=0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            val[cnt++]=ptr->val;
            ptr=ptr->next;
        }
        if(cnt<2){
            return head;
        }
        k=k%cnt;
        if(k==0){
            return head;
        }
        ptr=head;
        int idx=0;
        while(ptr!=NULL){
            if(idx<k){
                ptr->val=val[idx-k+cnt];
            }
            else{
                ptr->val=val[idx-k];
            }
            ptr=ptr->next;
            idx++;
        }
        return head;
    }
};