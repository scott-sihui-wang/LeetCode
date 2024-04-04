class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> sol;
        int len=nums.size();
        for(int i=0;i<len;i++){
            if(freq.find(nums[i])==freq.end()){
                freq[nums[i]]=1;
            }
            else{
                freq[nums[i]]++;
            }
        }
        unordered_map<int,int>::iterator iter;
        for(iter=freq.begin();iter!=freq.end();iter++){
            if(iter->second==1){
                sol.push_back(iter->first);
            }
        }
        return sol;
    }
};