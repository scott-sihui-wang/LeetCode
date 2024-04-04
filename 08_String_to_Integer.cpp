class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        while(s[i]==' '){
            i++;
        }
        bool neg;
        if(s[i]=='-'){
            neg=true;
            i++;
        }
        else if(s[i]=='+'){
            neg=false;
            i++;
        }
        else{
            neg=false;
        }
        int val=0;
        while(s[i]-'0'>=0 && s[i]-'0'<=9){
            if(neg){
                if(val<-214748364 || (val==-214748364 && s[i]>'8')){
                    return -2147483648;
                }
                else{
                    val=val*10-(s[i]-'0');
                }
            }
            else{
                if(val>214748364 || (val==214748364 && s[i]>'7')){
                    return 2147483647;
                }
                else{
                    val=val*10+(s[i]-'0');
                }
            }
            i++;
        }
        return val;
    }
};