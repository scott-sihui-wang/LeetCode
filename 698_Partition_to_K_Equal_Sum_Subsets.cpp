class Solution {
public:
    bool DFS(vector<int>& nums, vector<bool>& visited, int idx, int cur_sum, int sum, int subsets){
        if(subsets==1){
            return true;
        }
        if(idx>=nums.size()){
            return false;
        }
        if(cur_sum==sum){
            return DFS(nums,visited,0,0,sum,subsets-1);
        }
        for(int i=idx;i<nums.size();i++){
            if(visited[i]==false && cur_sum+nums[i]<=sum){
                visited[i]=true;
                bool ans=DFS(nums,visited,i+1,cur_sum+nums[i],sum,subsets);
                if(ans)return ans;
                visited[i]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1)return true;
        if(nums.size()<k)return false;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%k!=0)return false;
        sort(nums.begin(),nums.end(),greater<int>());
        vector<bool> visited(nums.size(),false);
        return DFS(nums,visited,0,0,sum/k,k);
    }
};