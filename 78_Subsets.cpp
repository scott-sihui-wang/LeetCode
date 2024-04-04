class Solution {
public:
    void solve(vector<int>& nums,int r,int n,vector<vector<int> >&sol,bool* sub_sol){
        if(r==n){
            sub_sol[r-1]=false;
            vector<int> tmp1;
            for(int i=0;i<r;i++){
                if(sub_sol[i]){
                    tmp1.push_back(nums[i]);
                }
            }
            sol.push_back(tmp1);
            sub_sol[r-1]=true;
            vector<int> tmp2;
            for(int i=0;i<r;i++){
                if(sub_sol[i]){
                    tmp2.push_back(nums[i]);
                }
            }
            sol.push_back(tmp2);
        }
        else{
            sub_sol[r-1]=false;
            solve(nums,r+1,n,sol,sub_sol);
            sub_sol[r-1]=true;
            solve(nums,r+1,n,sol,sub_sol);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >sol;
        int len=nums.size();
        bool* sub_sol=new bool[len];
        solve(nums,1,len,sol,sub_sol);
        return sol;
    }
};