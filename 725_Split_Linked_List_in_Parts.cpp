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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if(head==nullptr){
            vector<ListNode*>ans(k,head);
            return ans;
        }
        int cnt=1;
        ListNode* ptr=head;
        while(ptr->next!=nullptr){
            ptr=ptr->next;
            cnt++;
        }
        int num=cnt/k;
        int r=cnt%k;
        vector<ListNode*>ans(k);
        ptr=head;
        ListNode* tail=head;
        for(int i=0;i<r;i++){
            int idx=1;
            while(idx<num+1){
                idx++;
                tail=tail->next;
            }
            ans[i]=ptr;
            ptr=tail->next;
            tail->next=nullptr;
            tail=ptr;
        }
        for(int i=r;i<k;i++){
            if(num==0){
                continue;
            }
            else{
                int idx=1;
                while(idx<num){
                    idx++;
                    tail=tail->next;
                }
                ans[i]=ptr;
                ptr=tail->next;
                tail->next=nullptr;
                tail=ptr;
            }
        }
        return ans;
    }
};