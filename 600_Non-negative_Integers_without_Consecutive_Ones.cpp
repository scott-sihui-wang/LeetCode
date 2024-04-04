class Solution {
public:
    int rank(int n){
        int cnt=0;
        while(n>1){
            n=n/2;
            cnt++;
        }
        return cnt;
    }
    int solve(int n,int table[]){
        if(n==0)return 1;
        int val=rank(n+1);
        int residual=n+1-pow(2,val);
        if(residual==0){
            return table[val];
        }
        else{
            int val_r=rank(residual);
            if(val_r+1==val){
                return table[val]+table[val-1];
            }
            else{
                return table[val]+solve(residual-1,table);
            }
        }
    }
    int findIntegers(int n) {
        int table[31];
        memset(table,0,sizeof(table));
        table[0]=1;
        table[1]=2;
        table[2]=3;
        for(int i=3;i<31;i++){
            table[i]=table[i-1]+table[i-2];
        }
        return solve(n,table);
    }
};