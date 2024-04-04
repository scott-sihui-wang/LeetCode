class Solution {
public:
    int findComplement(int num) {
        if(num>(1<<30)){
            return (1<<30)-(num-(1<<30))-1;
        }
        int cnt=0;
        int n=num;
        while(n>0){
            cnt++;
            n=n/2;
        }
        return (1<<cnt)-1-num;
    }
};