class Solution {
public:
    int countPrimes(int n) {
        if(n<2){
            return 0;
        }
        bool isPrime[n-1];
        memset(isPrime,true,sizeof(isPrime));
        int cnt=0;
        for(int i=2;i<n;i++){
            if(isPrime[i-1]){
                cnt++;
                for(int j=2;j*i<n;j++){
                    isPrime[i*j-1]=false;
                }
            }
        }
        return cnt;
    }
};