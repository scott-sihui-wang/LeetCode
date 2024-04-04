/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        unordered_map<ListNode*,int> node_list;
        int cnt=0;
        node_list[head]=cnt++;
        ListNode* ptr=head;
        while(ptr!=NULL && ptr->next!=NULL){
            unordered_map<ListNode*,int>::iterator iter;
            iter=node_list.find(ptr->next);
            if(iter!=node_list.end()){
                return iter->first;
            }
            else{
                node_list[ptr->next]=cnt++;
                ptr=ptr->next;
            }
        }
        return NULL;
    }
};