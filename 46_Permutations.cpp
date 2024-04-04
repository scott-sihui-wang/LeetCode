class Solution {
public:
    void find_solution(int len,bool* used,int r,int* sol,vector<vector<int> >&sols,vector<int>& nums){
        for(int i=0;i<len;i++){
            if(used[i]==false){
                used[i]=true;
                sol[len-r]=nums[i];
                if(r>1){
                    find_solution(len,used,r-1,sol,sols,nums);
                }
                else{
                    vector<int> final_sol(len);
                    for(int j=0;j<len;j++){
                        final_sol[j]=sol[j];
                    }
                    sols.push_back(final_sol);
                }
                used[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int> > sols;
        bool used[len];
        int sol[len];
        for(int i=0;i<len;i++){
            used[i]=false;
        }
        find_solution(len,used,len,sol,sols,nums);
        return sols;
    }
};