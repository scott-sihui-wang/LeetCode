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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1!=nullptr){
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2!=nullptr){
            s2.push(l2->val);
            l2=l2->next;
        }
        int val,s=0;
        ListNode *ptr,*tail=nullptr;
        while(!s1.empty() && !s2.empty()){
            val=s1.top()+s2.top()+s;
            s=val/10;
            val=val%10;
            ptr=new ListNode(val,tail);
            s1.pop();
            s2.pop();
            tail=ptr;
        }
        while(!s1.empty()){
            val=s1.top()+s;
            s=val/10;
            val=val%10;
            ptr=new ListNode(val,tail);
            s1.pop();
            tail=ptr;
        }
        while(!s2.empty()){
            val=s2.top()+s;
            s=val/10;
            val=val%10;
            ptr=new ListNode(val,tail);
            s2.pop();
            tail=ptr;
        }
        if(s!=0){
            ptr=new ListNode(s,tail);
        }
        return ptr;
    }
};