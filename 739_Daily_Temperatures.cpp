class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mono_stack;
        vector<int> ans(temperatures.size());
        for(int i=0;i<temperatures.size();i++){
            while(!mono_stack.empty() && temperatures[mono_stack.top()]<temperatures[i]){
                int idx=mono_stack.top();
                ans[idx]=i-idx;
                mono_stack.pop();
            }
            mono_stack.push(i);
        }
        return ans;
    }
};