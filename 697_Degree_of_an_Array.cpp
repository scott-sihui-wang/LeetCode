class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int freq[50000];
        int lower[50000];
        int upper[50000];
        memset(freq,0,sizeof(freq));
        memset(lower,-1,sizeof(lower));
        memset(upper,-1,sizeof(upper));
        int len=nums.size();
        for(int i=0;i<len;i++){
            freq[nums[i]]++;
            if(freq[nums[i]]==1){
                lower[nums[i]]=i;
                upper[nums[i]]=i;
            }
            else{
                upper[nums[i]]=i;
            }
        }
        int max_freq=0;
        int range=INT_MAX;
        for(int i=0;i<50000;i++){
            if(freq[i]>max_freq){
                max_freq=freq[i];
                range=upper[i]-lower[i]+1;
            }
            else if(freq[i]==max_freq && upper[i]-lower[i]+1<range){
                range=upper[i]-lower[i]+1;
            }
        }
        return range;
    }
};