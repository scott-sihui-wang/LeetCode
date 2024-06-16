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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int>next,prev;
        unordered_map<int,int>n;
        for(ListNode* ptr=head;ptr!=nullptr;ptr=ptr->next){
            if(ptr->next!=nullptr){
                next[ptr->val]=ptr->next->val;
                prev[ptr->next->val]=ptr->val;
            }
            else{
                next[ptr->val]=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            n[nums[i]]=i;
        }
        int ans=0;
        int components[nums.size()];
        memset(components,0,sizeof(components));
        for(int i=0;i<nums.size();i++){
            if(components[i]==0){
                ans++;
                components[i]=ans;
                int val=nums[i];
                while(next[val]!=-1 && n.find(next[val])!=n.end()){
                    val=next[val];
                    components[n[val]]=ans;
                }
                val=nums[i];
                while(prev.find(val)!=prev.end() && n.find(prev[val])!=n.end()){
                    val=prev[val];
                    components[n[val]]=ans;
                }
            }
        }
        return ans;
    }
};