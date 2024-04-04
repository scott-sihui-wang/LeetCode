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
    bool isPalindrome(ListNode* head) {
        int val[100000];
        int cnt=0;
        while(head!=NULL){
            val[cnt++]=head->val;
            head=head->next;
        }
        for(int i=0;i<cnt/2;i++){
            if(val[i]!=val[cnt-1-i]){
                return false;
            }
        }
        return true;
    }
};