class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>sol(n+1);
        sol[0]=0;
        int prev_top=1;
        int top=1;
        int iter=n;
        while(iter>0){
            for(int i=0;i<prev_top && top<=n;i++){
                sol[top++]=sol[i]+1;
            }
            prev_top=top;
            iter=iter/2;
        }
        return sol;
    }
};