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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || k==1){
            return head;
        }
        int val[5000];
        ListNode* ptr=head;
        int cnt=0;
        while(ptr!=NULL){
            val[cnt++]=ptr->val;
            ptr=ptr->next;
        }
        if(cnt==1){
            return head;
        }
        //int idx=0;
        ptr=head;
        int num_group=cnt/k;
        for(int i=0;i<num_group;i++){
            for(int j=0;j<k;j++){
                ptr->val=val[(i+1)*k-1-j];
                ptr=ptr->next;
            }
        }
        //for(int idx=0;idx<num_group*k;idx++){
            //int id=idx%k;
            //int n_group=idx/k;
            //ptr->val=val[(n_group+1)*k-1-id];
            //ptr=ptr->next;
        //}
        return head;
    }
};