class Solution {
public:
    int GCD(int a,int b){
        if(a<b){
            return GCD(b,a);
        }
        if(a%b==0){
            return b;
        }
        else{
            return GCD(b,a%b);
        }
    }
    string fractionAddition(string expression) {
        bool sign_a=true;
        bool sign_b=(expression[0]=='-'?false:true);
        int i=(expression[0]=='-'?1:0);
        int numerator_a=0,denominator_a=1;
        int numerator_b,denominator_b;
        while(i<expression.size()){
            numerator_b=0;
            while(i<expression.size() && expression[i]>='0' && expression[i]<='9'){
                numerator_b=numerator_b*10+expression[i]-'0';
                i++;
            }
            i++;
            denominator_b=0;
            while(i<expression.size() && expression[i]>='0' && expression[i]<='9'){
                denominator_b=denominator_b*10+expression[i]-'0';
                i++;
            }
            numerator_a=numerator_a*denominator_b*(sign_a?1:-1)+numerator_b*denominator_a*(sign_b?1:-1);
            denominator_a=denominator_a*denominator_b;
            sign_a=true;
            if(numerator_a<0){
                numerator_a=abs(numerator_a);
                sign_a=!sign_a;
            }
            if(denominator_a<0){
                denominator_a=abs(denominator_a);
                sign_a=!sign_a;
            }
            if(i<expression.size()){
                sign_b=(expression[i]=='-'?false:true);
                i++;
            }
        }
        if(numerator_a==0){
            denominator_a=1;
            sign_a=true;
        }
        else{
            int d=GCD(numerator_a,denominator_a);
            numerator_a/=d;
            denominator_a/=d;
        }
        return (sign_a==false?string("-"):string(""))+to_string(numerator_a)+"/"+to_string(denominator_a);
    }
};