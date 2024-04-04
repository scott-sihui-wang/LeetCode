class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        int len=max(len1,len2)+2;
        char sol[len];
        sol[len-1]='\0';
        int cur=len-2;
        int i=len1-1;
        int j=len2-1;
        int overflow=0;
        while(i>=0 || j>=0 || overflow!=0){
            int val=overflow;
            if(i>=0){
                val+=num1[i--]-'0';
            }
            if(j>=0){
                val+=num2[j--]-'0';
            }
            sol[cur--]=val%10+'0';
            overflow=val/10;
        }
        return string(sol+1+cur);
    }
};