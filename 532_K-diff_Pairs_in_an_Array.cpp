class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,bool>info;
        for(int i=0;i<nums.size();i++){
            if(info.find(nums[i])==info.end()){
                info[nums[i]]=false;
            }
            else{
                info[nums[i]]=true;
            }
        }
        int ans=0;
        if(k==0){
            for(auto iter=info.begin();iter!=info.end();iter++){
                if(iter->second)ans++;
            }
        }
        else{
            for(auto iter=info.begin();iter!=info.end();iter++){
                if(info.find(iter->first+k)!=info.end())ans++;
            }
        }
        return ans;
    }
};