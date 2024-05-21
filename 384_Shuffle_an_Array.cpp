class Solution {
public:
    vector<int> init;
    vector<int> ret;
    Solution(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            init.push_back(nums[i]);
            ret.push_back(nums[i]);
        }
    }
    
    vector<int> reset() {
        for(int i=0;i<init.size();i++){
            ret[i]=init[i];
        }
        return ret;
    }
    
    vector<int> shuffle() {
        for(int i=0;i<init.size();i++){
            ret[i]=init[i];
        }
        for(int i=0;i<ret.size();i++){
            int j=rand()%ret.size();
            int tmp=ret[i];
            ret[i]=ret[j];
            ret[j]=tmp;
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */