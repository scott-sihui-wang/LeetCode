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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* node_list[5000];
        int cnt=0;
        for(ListNode* ptr=head;ptr!=NULL;ptr=ptr->next){
            node_list[cnt++]=ptr;
        }
        for(int i=cnt-1;i>0;i--){
            for(int j=cnt-1;j>0;j--){
                int tmp=node_list[j]->val;
                if(node_list[j-1]->val>tmp){
                    node_list[j]->val=node_list[j-1]->val;
                    node_list[j-1]->val=tmp;
                }
            }
        }
        return head;
    }
};