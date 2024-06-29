class Solution {
public:
    int clumsy(int n) {
        if(n==1){
            return 1;
        }
        else if(n==2){
            return 2;
        }
        else if(n==3){
            return 6;
        }
        int ans=0;
        ans+=n*(n-1)/(n-2);
        n-=3;
        while(n>0){
            ans+=n;
            n--;
            if(n>=3){
                ans-=n*(n-1)/(n-2);
                n-=3;
            }
            else if(n==2){
                ans-=n*(n-1);
                n-=2;
            }
            else if(n==1){
                ans-=n;
                n-=1;
            }
        }
        return ans;
    }
};