class Solution {
public:
    int tribonacci(int n) {
        if(n==0){
            return 0;
        }
        else if(n==1){
            return 1;
        }
        else if(n==2){
            return 1;
        }
        else{
            int sol[n+1];
            sol[0]=0;
            sol[1]=1;
            sol[2]=1;
            for(int i=3;i<n+1;i++){
                sol[i]=sol[i-1]+sol[i-2]+sol[i-3];
            }
            return sol[n];
        }
    }
};