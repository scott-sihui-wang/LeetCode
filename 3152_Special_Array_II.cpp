class Solution {
public:
    bool diff_parity(int i1,int i2){
        return (i1%2==0 && i2%2==1) || (i1%2==1 && i2%2==0);
    }
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<pair<pair<int,int>,int>> v;
        for(int i=0;i<queries.size();i++){
            v.push_back({{queries[i][0],queries[i][1]},i});
        }
        sort(v.begin(),v.end());
        vector<bool> ans(queries.size());
        int start_idx=0,end_idx=0;
        int idx_v=0;
        while(end_idx<nums.size()-1){
            while(end_idx<nums.size()-1 && diff_parity(nums[end_idx],nums[end_idx+1])){
                end_idx++;
            }
            while(idx_v<v.size() && v[idx_v].first.first<=end_idx){
                if(v[idx_v].first.first>=start_idx && v[idx_v].first.second<=end_idx){
                    ans[v[idx_v].second]=true;
                }
                else{
                    ans[v[idx_v].second]=false;
                }
                idx_v++;
            }
            start_idx=end_idx;
            while(start_idx<nums.size()-1 && !diff_parity(nums[start_idx],nums[start_idx+1])){
                while(idx_v<v.size() && v[idx_v].first.first<=end_idx){
                    if(v[idx_v].first.first>=start_idx && v[idx_v].first.second<=end_idx){
                        ans[v[idx_v].second]=true;
                    }
                    else{
                        ans[v[idx_v].second]=false;
                    }
                    idx_v++;
                }
                start_idx++;
                end_idx++;
            }
        }
        while(idx_v<v.size() && v[idx_v].first.first<=end_idx){
            if(v[idx_v].first.first>=start_idx && v[idx_v].first.second<=end_idx){
                ans[v[idx_v].second]=true;
            }
            else{
                ans[v[idx_v].second]=false;
            }
            idx_v++;
        }
        while(idx_v<v.size()){
            ans[v[idx_v].second]=false;
            idx_v++;
        }
        return ans;
    }
};