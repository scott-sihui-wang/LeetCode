class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
       vector<pair<int,int>>idx;
       for(int i=0;i<nums.size();i++){
            idx.push_back({nums[i],i});
       }
       sort(idx.begin(),idx.end());
       int i=0;
       while(i<idx.size()){
            while(i<idx.size() && idx[i].second==i){
                i++;
            }
            if(i<idx.size()){
                if(i<idx.size()-1 && idx[i].second==i+1 && idx[i+1].second==i){
                    i+=2;
                    continue;
                }
                else{
                    return false;
                }
            }
       }
       return true;
    }
};