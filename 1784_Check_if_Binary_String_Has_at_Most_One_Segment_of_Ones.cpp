class Solution {
public:
    bool checkPowersOfThree(int n) {
        int digit[15];
        int top=-1;
        while(n!=0){
            digit[++top]=n%3;
            n=n/3;
        }
        for(int i=0;i<=top;i++){
            if(digit[i]==2){
                return false;
            }
        }
        return true;
    }
};