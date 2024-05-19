class Solution {
public:
    int solve(int n){
        if(n==1){
            return 1;
        }
        if(n%2==1){
            return solve(n-1);
        }
        else{
            return n-2*solve(n/2)+2;
        }
    }
    int lastRemaining(int n) {
        return solve(n);
    }
};