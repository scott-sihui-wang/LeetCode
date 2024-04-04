class Solution {
public:
    void solve(vector<int>& coins, int amount, int sol[]){
        for(int i=0;i<coins.size();i++){
            if(amount-coins[i]>=0 && sol[amount-coins[i]]>=0){
                if(sol[amount]>=0){
                    sol[amount]=min(sol[amount],sol[amount-coins[i]]+1);
                }
                else{
                    sol[amount]=sol[amount-coins[i]]+1;
                }
            }
            else if(amount-coins[i]>=0 && sol[amount-coins[i]]==-2){
                solve(coins,amount-coins[i],sol);
                if(sol[amount-coins[i]]==-1){
                    if(sol[amount]==-2){
                        sol[amount]=-1;
                    }
                }
                else{
                    if(sol[amount]<0){
                        sol[amount]=sol[amount-coins[i]]+1;
                    }
                    else{
                        sol[amount]=min(sol[amount],sol[amount-coins[i]]+1);
                    }
                }
            }
            else if(amount-coins[i]>=0 && sol[amount-coins[i]]==-1){
                if(sol[amount]==-2){
                    sol[amount]=-1;
                }
            }
            else if(amount-coins[i]<0){
                if(sol[amount]==-2){
                    sol[amount]=-1;
                }
            }
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        else if(amount<0){
            return -1;
        }
        else{
            int sol[10001];
            for(int i=0;i<10001;i++){
                sol[i]=-2;
            }
            sol[0]=0;
            solve(coins,amount,sol);
            return sol[amount];
        }
    }
};