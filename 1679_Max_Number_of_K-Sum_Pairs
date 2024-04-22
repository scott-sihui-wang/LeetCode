class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i])==freq.end()){
                freq[nums[i]]=1;
            }
            else{
                freq[nums[i]]++;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=k-nums[i]){
                if(freq[nums[i]]>0 && freq.find(k-nums[i])!=freq.end() && freq[k-nums[i]]>0){
                    ans+=min(freq[nums[i]],freq[k-nums[i]]);
                    freq[nums[i]]=0;
                    freq[k-nums[i]]=0;
                }
            }
            else{
                if(freq[nums[i]]>0){
                    ans+=freq[nums[i]]/2;
                    freq[nums[i]]=0;
                }
            }    
        }
        return ans;
    }
};
