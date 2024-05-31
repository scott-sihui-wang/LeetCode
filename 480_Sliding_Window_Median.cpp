class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> win(nums.begin(),nums.begin()+k);
        vector<double>ans;
        auto mid=next(win.begin(),k/2);
        for(int i=k;i<=nums.size();i++){
            ans.push_back(((double)*mid+(double)*prev(mid,1-k%2))/2);
            if(i==nums.size())continue;
            win.insert(nums[i]);
            if(nums[i]<*mid){
                mid--;
            }
            if(nums[i-k]<=*mid){
                mid++;
            }
            win.erase(win.lower_bound(nums[i-k]));
        }
        return ans;
    }
};