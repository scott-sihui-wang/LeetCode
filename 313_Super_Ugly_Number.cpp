class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n==1)return 1;
        long long num[n];
        num[0]=1;
        vector<int> ptr(primes.size(),0);
        for(int i=1;i<n;i++){
            long long m=LLONG_MAX;
            for(int j=0;j<ptr.size();j++){
                m=min(m,num[ptr[j]]*primes[j]);
            }
            num[i]=m;
            for(int j=0;j<ptr.size();j++){
                if(num[ptr[j]]*primes[j]==m){
                    ptr[j]++;
                }
            }
        }
        return num[n-1];
    }
};