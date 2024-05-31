class Solution {
public:
    string smallestGoodBase(string n) {
        long long num=stoll(n);
        for(long long m=log2(num);m>=2;m--){
            long long k=pow(num,1.0/m);
            long long sum=1;
            long long p=1;
            for(long long i=0;i<m;i++){
                p*=k;
                sum+=p;
            }
            if(sum==num)return to_string(k);
        }
        return to_string(num-1);
    }
};