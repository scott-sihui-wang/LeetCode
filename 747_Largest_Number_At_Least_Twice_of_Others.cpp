class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        if(v[v.size()-1].first>=2*v[v.size()-2].first){
            return v[v.size()-1].second;
        }
        else{
            return -1;
        }
    }
};