class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        int len=len1+len2+1;
        char sol[len];
        int res[len-1];
        for(int i=0;i<len-1;i++){
            res[i]=0;
        }
        for(int i=len2-1;i>=0;i--){
            for(int j=len1-1;j>=0;j--){
                res[i+j+1]+=(num1[j]-'0')*(num2[i]-'0');
            }
        }
        for(int i=len-2;i>=1;i--){
            res[i-1]+=res[i]/10;
            res[i]=res[i]%10;
        }
        int start=0;
        while(start<len-1 && res[start]==0){
            start++;
        }
        if(start==len-1){
            return string("0");
        }
        else{
            for(int i=start;i<len-1;i++){
                sol[i-start]=res[i]+'0';
            }
            sol[len-1-start]='\0';
            return string(sol);
        }
    }
};