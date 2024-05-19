class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)return 1;
        int n1=9,n2=1;
        int mul1=9,mul2=0;
        int sum=n1+n2;
        while(n>1){
            n2*=mul1;
            n1*=(--mul1);
            sum+=n1+n2*(++mul2);
            n--;
        }
        return sum;
    }
};