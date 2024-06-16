class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int max_val=INT_MIN,min_val=INT_MAX;
        for(int i=0;i<k;i++){
            max_val=max(max_val,nums[i][0]);
            min_val=min(min_val,nums[i][0]);
            pq.push({nums[i][0],i,0});
        }
        int left=min_val,right=max_val;
        while(!pq.empty()){
            vector<int> elem=pq.top();
            pq.pop();
            if(right-left>max_val-elem[0]){
                left=elem[0];
                right=max_val;
            }
            if(elem[2]+1<nums[elem[1]].size()){
                pq.push({nums[elem[1]][elem[2]+1],elem[1],elem[2]+1});
                max_val=max(max_val,nums[elem[1]][elem[2]+1]);
            }
            else{
                break;
            }
        }
        return {left,right};
    }
};