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
    ListNode* removeNodes(ListNode* head) {
        stack<int> m_st;
        while(head!=nullptr){
            while(!m_st.empty() && m_st.top()<head->val){
                m_st.pop();
            }
            m_st.push(head->val);
            head=head->next;
        }
        ListNode* ptr=new ListNode(m_st.top());
        m_st.pop();
        while(!m_st.empty()){
            ListNode* pa=new ListNode(m_st.top(),ptr);
            m_st.pop();
            ptr=pa;
        }
        return ptr;
    }
};