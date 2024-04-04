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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> traceA;
        while(headA!=nullptr){
            traceA.insert(headA);
            headA=headA->next;
        }
        while(headB!=nullptr){
            unordered_set<ListNode*>::iterator iter=traceA.find(headB);
            if(iter!=traceA.end()){
                return *iter;
            }
            headB=headB->next;
        }
        return nullptr;    
    }
};