class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int> >& sol, int* sel, int target, int idx_c, int idx_s){
        int len=candidates.size();
        for(int i=idx_c;i<len;i++){
            if(target>candidates[i]){
                sel[idx_s]=candidates[i];
                solve(candidates,sol,sel,target-candidates[i],i,idx_s+1);
            }
            else if(target==candidates[i]){
                vector<int> sub_sol;
                for(int j=0;j<idx_s;j++){
                    sub_sol.push_back(sel[j]);
                }
                sub_sol.push_back(candidates[i]);
                sol.push_back(sub_sol);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> >sol;
        int sel[500];
        solve(candidates,sol,sel,target,0,0);
        return sol;
    }
};