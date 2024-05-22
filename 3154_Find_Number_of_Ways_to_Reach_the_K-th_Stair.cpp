class Solution {
public:
    long long comb(int n,int k){
        if(n<2*k){
            k=n-k;
        }
        long long res=1,mul_n=n,mul_d=1;
        for(int i=0;i<k;i++){
            res=res*mul_n/mul_d;
            mul_n--;
            mul_d++;
        }
        return res;
    }
    int waysToReachStair(int k) {
        int ans=0;
        int y=0;
        while((1<<y)-k<0){
            y++;
        }
        while((1<<y)-k<=y+1){
            ans+=comb(y+1,(1<<y)-k);
            y++;
        }
        return ans;
    }
};