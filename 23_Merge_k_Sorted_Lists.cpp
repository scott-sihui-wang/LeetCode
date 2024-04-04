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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len=lists.size();
        if(len==0){
            return NULL;
        }
        ListNode* ptr[len];
        for(int i=0;i<len;i++){
            ptr[i]=lists[i];
        }
        ListNode* merged=new ListNode();
        ListNode* head=merged;
        int min_val;
        do{
            min_val=INT_MAX;
            int min_idx=-1;
            for(int i=0;i<len;i++){
                if(ptr[i]==NULL)continue;
                if(ptr[i]->val<min_val){
                    min_val=ptr[i]->val;
                    min_idx=i;
                }
            }
            if(min_idx!=-1){
                merged->next=new ListNode(ptr[min_idx]->val);
                merged=merged->next;
                ptr[min_idx]=ptr[min_idx]->next;
            }
        }while(min_val<INT_MAX);
        return head->next;
    }
};