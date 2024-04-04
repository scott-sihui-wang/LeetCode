class Solution {
public:
    void solve(int k,int n,int* sol,int idx,vector<vector<int> >&result){
        if(k==1){
            if(n>=1 && n<=9 && n>sol[idx-1]){
                vector<int> sub_sol(idx+1);
                for(int i=0;i<idx;i++){
                    sub_sol[i]=sol[i];
                }
                sub_sol[idx]=n;
                result.push_back(sub_sol);
            }
        }
        else{
            int val;
            if(idx==0){
                val=1;
            }
            else{
                val=sol[idx-1]+1;
            }
            for(;val<10;val++){
                sol[idx]=val;
                solve(k-1,n-val,sol,idx+1,result);
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int* sol=new int[9];
        vector<vector<int> >result;
        solve(k,n,sol,0,result);
        return result;
    }
};