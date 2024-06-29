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
    vector<int> nextLargerNodes(ListNode* head) {
        unordered_map<ListNode*,pair<int,int>>dict;
        stack<ListNode*>s;
        int idx=0;
        ListNode* ptr=head;
        while(ptr!=nullptr){
            while(!s.empty() && ptr->val>s.top()->val){
                dict[s.top()].second=ptr->val;
                s.pop();
            }
            s.push(ptr);
            dict[ptr]={idx,0};
            ptr=ptr->next;
            idx++;
        }
        vector<int>ans(idx);
        for(auto iter=dict.begin();iter!=dict.end();iter++){
            ans[iter->second.first]=iter->second.second;
        }
        return ans;
    }
};