class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len=nums.size();
        unordered_map<int,int> freq;
        unordered_map<int,int>::iterator iter;
        int max_freq=0;
        int max_num;
        for(int i=0;i<len;i++){
            iter=freq.find(nums[i]);
            if(iter==freq.end()){
                freq[nums[i]]=1;
                if(max_freq<1){
                    max_freq=1;
                    max_num=nums[i];
                }
            }
            else{
                iter->second=iter->second+1;
                if(iter->second>max_freq){
                    max_freq=iter->second;
                    max_num=iter->first;
                }
            }
        }
        return max_num;
    }
};