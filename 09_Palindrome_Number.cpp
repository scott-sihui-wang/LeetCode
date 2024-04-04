class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        else if(x==0){
            return true;
        }
        else{
            int digits[10];
            int cnt=0;
            while(x!=0){
                digits[cnt++]=x%10;
                x=x/10;
            }
            for(int i=0;i<cnt/2;i++){
                if(digits[i]!=digits[cnt-1-i]){
                    return false;
                }
            }
            return true;
        }
    }
};