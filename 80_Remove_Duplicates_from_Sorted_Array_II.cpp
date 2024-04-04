class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len=nums.size();
        int processed_end=-1;
        int freq[20001];
        const int lower_bound=10000;
        memset(freq,0,sizeof(freq));
        for(int i=0;i<len;i++){
            int idx=nums[i]+lower_bound;
            freq[idx]++;
            if(freq[idx]<=2){
                swap(nums[++processed_end],nums[i]);
            }
        }
        return processed_end+1;
    }
};