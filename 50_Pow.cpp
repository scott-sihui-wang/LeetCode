class Solution {
public:
    double myPow(double x, int n) {
        if(n==0)return 1;
        unsigned int m=abs(n);
        if(n<0){
            x=1.0/x;
        }
        double ans=1.0;
        while(m!=0){
            if(m%2!=0){
                ans=ans*x;
            }
            x=x*x;
            m=m/2;
        }
        return ans;
    }
};