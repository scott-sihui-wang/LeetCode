class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>dict;
        for(int i=0;i<nums.size();i++){
            if(dict.find(nums[i])==dict.end()){
                dict[nums[i]]=1;
            }
            else{
                dict[nums[i]]++;
            }
        }
        vector<pair<int,int>>freq;
        unordered_map<int,int>::iterator iter;
        for(iter=dict.begin();iter!=dict.end();iter++){
            freq.push_back({iter->second,iter->first});
        }
        sort(freq.begin(),freq.end(),greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(freq[i].second);
        }
        return ans;
    }
};