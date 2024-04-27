class Solution {
public:
    string numToW(int num){
        string n1[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string n2[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string n3[8]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string splitter(" ");
        if(0<=num && num<=9){
            return n1[num];
        }
        else if(10<=num && num<=19){
            return n2[num-10];
        }
        else if(num>=20 && num<=99){
            if(num%10==0){
                return n3[num/10-2];
            }
            else{
                return n3[num/10-2]+splitter+n1[num%10];
            }
        }
        return string("");
    }
    string numToW2(int num){
        string splitter(" ");
        string n1[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string n2[10]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string n3[8]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        if(0<=num && num<=99){
            return numToW(num);
        }
        else if(num>=100 && num<=999){
            if(num%100==0){
                return n1[num/100]+splitter+string("Hundred");
            }
            else{
                return n1[num/100]+splitter+string("Hundred")+splitter+numToW(num%100);
            }
        }
        return string("");
    }
    string numberToWords(int num) {
        if(num==0)return string("Zero");
        string ans("");
        string splitter(" ");
        bool cont=false;
        if(num/1000000000!=0){
            ans+=numToW(num/1000000000)+splitter+string("Billion");
            cont=true;
        }
        if((num%1000000000)/1000000!=0){
            ans+=(cont?splitter:string(""))+numToW2((num%1000000000)/1000000)+splitter+string("Million");
            cont=true;
        }
        if((num%1000000)/1000!=0){
            ans+=(cont?splitter:string(""))+numToW2((num%1000000)/1000)+splitter+string("Thousand");
            cont=true;
        }
        if(num%1000!=0){
            ans+=(cont?splitter:string(""))+numToW2(num%1000);
        }
        return ans;
    }
};