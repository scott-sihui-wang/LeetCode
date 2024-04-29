class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            if(freq.find(nums[i])==freq.end()){
                freq[nums[i]]=1;
            }
            else{
                freq[nums[i]]++;
            }
        }
        bool available=true;
        unordered_map<int,int>::iterator iter;
        vector<vector<int>>ans;
        while(available){
            vector<int>row;
            for(iter=freq.begin();iter!=freq.end();iter++){
                if(iter->second>0){
                    row.push_back(iter->first);
                    iter->second--;
                }
            }
            if(row.size()!=0){
                ans.push_back(row);
            }
            else{
                available=false;
            }
        }
        return ans;
    }
};