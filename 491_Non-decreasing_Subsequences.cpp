class Solution {
public:
    void DFS(vector<int>& nums,int idx,vector<int>& path,vector<vector<int>>& ans,set<vector<int>>&s){
        for(int i=idx;i<nums.size();i++){
            if(path.size()==0 || path[path.size()-1]<=nums[i]){
                path.push_back(nums[i]);
                if(path.size()>1 && s.find(path)==s.end()){
                    ans.push_back(path);
                    s.insert(path);
                }
                DFS(nums,i+1,path,ans,s);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>path;
        set<vector<int>>s;
        DFS(nums,0,path,ans,s);
        return ans;   
    }
};