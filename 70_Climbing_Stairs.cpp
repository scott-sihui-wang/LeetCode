class Solution {
public:
    int climbStairs(int n) {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            int sol[n];
            sol[0]=1;
            sol[1]=2;
            for(int i=2;i<n;i++){
                sol[i]=sol[i-1]+sol[i-2];
            }
            return sol[n-1];
        }
    }
};