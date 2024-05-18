class Solution {
public:
    int findKthNumber(int n, int k) {
        long long n1=1,n2=n1+1;
        k--;
        while(k>0){
            long long m=cnt(n1,n2,n);
            if(m<=k){
                n1=n2;
                n2++;
                k-=m;
            }
            else{
                n1*=10;
                n2=n1+1;
                k--;
            }
        }
        return n1;
    }
    long long cnt(long long n1,long long n2,long long n){
        long long ans=0;
        while(n1<=n){
            ans+=min(n+1,n2)-n1;
            n1*=10;
            n2*=10;
        }
        return ans;
    }
};