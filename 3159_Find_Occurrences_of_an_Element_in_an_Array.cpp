class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int>occurrence;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                occurrence.push_back(i);
            }
        }
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            if(queries[i]<=occurrence.size()){
                ans.push_back(occurrence[queries[i]-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};