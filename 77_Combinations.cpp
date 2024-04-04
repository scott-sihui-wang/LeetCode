class Solution {
public:
    void solve(int n,int k,int cur,int begin,int* sub_sol,vector<vector<int> >&sol){
        if(cur==k){
            for(int i=begin;i<=n;i++){
                sub_sol[cur-1]=i;
                vector<int> tmp;
                for(int j=0;j<cur;j++){
                    tmp.push_back(sub_sol[j]);
                }
                sol.push_back(tmp);
            }
        }
        else{
            for(int i=begin;i<=n-k+cur;i++){
                sub_sol[cur-1]=i;
                solve(n,k,cur+1,i+1,sub_sol,sol);
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >sol;
        int* sub_sol=new int[n];
        solve(n,k,1,1,sub_sol,sol);
        return sol;
    }
};