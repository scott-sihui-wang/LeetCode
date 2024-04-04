class Solution {
public:
    bool outOfRange(int* num,int* range,int len){
        int idx=0;
        while(idx<len){
            if(num[idx]<range[idx]){
                return false;
            }
            else if(num[idx]==range[idx]){
                idx++;
            }
            else{
                return true;
            }
        }
        return false;
    }
    int reverse(int x) {
        if(x==0 || x==-2147483648){
            return 0;
        }
        bool isPositive;
        if(x>0){
            isPositive=true;
        }
        else{
            isPositive=false;
            x=-x;
        }
        int digits[10];
        int p_bound[10]={2,1,4,7,4,8,3,6,4,7};
        int n_bound[10]={2,1,4,7,4,8,3,6,4,8};
        int cnt=0;
        while(x>0){
            digits[cnt++]=x%10;
            x=x/10;
        }
        if(cnt==10){
            if(isPositive==false){
                if(outOfRange(digits,n_bound,10)==true){
                    return 0;
                }
            }
            else{
                if(outOfRange(digits,p_bound,10)==true){
                    return 0;
                }
            }
        }
        int result=0;
        for(int i=0;i<cnt;i++){
            result=result*10;
            result+=digits[i];
        }
        if(isPositive==false){
            result=-result;
        }
        return result;
    }
};