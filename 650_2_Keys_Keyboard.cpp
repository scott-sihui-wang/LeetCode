class Solution {
public:
    int minSteps(int n) {
        int div=2;
        int ans=0;
        while(n>1){
            while(n%div==0){
                ans+=div;
                n=n/div;
            }
            div++;
        }
        return ans;
    }
};