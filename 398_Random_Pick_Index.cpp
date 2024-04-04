class Solution {
public:
    
    unordered_map<int,vector<int> >dict;
    unordered_map<int,int> cnt;
    
    Solution(vector<int>& nums) {
        int len=nums.size();
        unordered_map<int,vector<int> >::iterator iter1;
        unordered_map<int,int>::iterator iter2;
        for(int i=0;i<len;i++){
            iter1=dict.find(nums[i]);
            if(iter1==dict.end()){
                dict[nums[i]]=vector<int>(1,i);
                cnt[nums[i]]=1;
            }
            else{
                iter1->second.push_back(i);
                iter2=cnt.find(nums[i]);
                iter2->second=iter2->second+1;
            }
        }
    }
    
    int pick(int target) {
        return dict[target][rand()%(cnt[target])];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */