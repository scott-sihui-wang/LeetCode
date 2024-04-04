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
    void reorderList(ListNode* head) {
        ListNode* node_list[50000];
        int top=0;
        ListNode* ptr=head;
        while(ptr!=NULL){
            node_list[top++]=ptr;
            ptr=ptr->next;
        }
        for(int i=0;i<(top-1)/2;i++){
            node_list[i]->next=node_list[top-1-i];
            node_list[top-1-i]->next=node_list[i+1];
        }
        node_list[top/2]->next=NULL;
    }
};