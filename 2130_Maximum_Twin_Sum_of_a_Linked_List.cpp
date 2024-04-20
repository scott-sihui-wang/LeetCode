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
    int pairSum(ListNode* head) {
        vector<int> nums;
        while(head!=nullptr){
            nums.push_back(head->val);
            head=head->next;
        }
        int ans=INT_MIN;
        for(int i=0;i<nums.size()/2;i++){
            ans=max(ans,nums[i]+nums[nums.size()-1-i]);
        }
        return ans;
    }
};