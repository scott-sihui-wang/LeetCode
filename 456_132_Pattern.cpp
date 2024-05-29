class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        int min_so_far=nums[0];
        vector<int> min_prev(n,0);
        for(int i=0;i<n;i++){
            min_so_far=min(min_so_far,nums[i]);
            min_prev[i]=min_so_far;
        }
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==min_prev[i]){
                continue;
            }
            while(!s.empty() && s.top()<=min_prev[i]){
                s.pop();
            }
            if(!s.empty() && s.top()<nums[i]){
                return true;
            }
            s.push(nums[i]);
        }
        return false;
    }
};