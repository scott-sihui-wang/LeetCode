class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> num;
        unordered_map<int,int>::iterator iter;
        vector<int> sol;
        for(int i=0;i<nums.size();i++){
            iter=num.find(nums[i]);
            if(iter==num.end()){
                num[nums[i]]=i;
            }
            else{
                num[nums[i]]=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            if(num.find(nums[i]-1)==num.end() && num.find(nums[i]+1)==num.end() && num[nums[i]]!=-1){
                sol.push_back(nums[i]);
            }
        }
        return sol;
    }
};