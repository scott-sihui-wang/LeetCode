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
    ListNode* doubleIt(ListNode* head) {
        stack<int> s;
        while(head!=nullptr){
            s.push(head->val);
            head=head->next;
        }
        ListNode *ptr=nullptr,*new_head;
        int p=0;
        while(!s.empty()){
            new_head=new ListNode((s.top()*2+p)%10,ptr);
            p=(s.top()*2+p)/10;
            ptr=new_head;
            s.pop();
        }
        if(p>0){
            new_head=new ListNode(p,ptr);
            ptr=new_head;
        }
        return ptr;
    }
};