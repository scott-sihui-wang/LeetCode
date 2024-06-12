class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64>bx,bn;
        int i=0;
        while(x!=0){
            bx[i]=x%2;
            x=x/2;
            i++;
        }
        i=0;
        n--;
        while(n!=0){
            bn[i]=n%2;
            n=n/2;
            i++;
        }
        i=0;
        int j=0;
        while(i<64){
            while(i<64 && bx[i]==1){
                i++;
            }
            while(i<64 && bx[i]==0){
                bx[i]=bn[j];
                i++;
                j++;
            }
        }
        long long ans=0;
        for(int i=0;i<64;i++){
            if(bx[i]==1){
                ans+=(long long)1<<i;
            }
        }
        return ans;
    }
};