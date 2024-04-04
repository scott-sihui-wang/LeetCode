class Solution {
public:
    int numTrees(int n) {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else{
            int sol[n+1];
            sol[0]=1;
            sol[1]=1;
            sol[2]=2;
            for(int i=2;i<n;i++){
                int cnt=0;
                for(int j=0;j<=i;j++){
                    cnt+=sol[j]*sol[i-j];
                }
                sol[i+1]=cnt;
            }
            return sol[n];
        }
    }
};