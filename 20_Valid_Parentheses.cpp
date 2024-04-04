class Solution {
public:
    bool isValid(string s) {
        int b1=0;
        int b2=0;
        int b3=0;
        int bracket[10000];
        int top=-1;
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                b1++;
                top++;
                bracket[top]=1;
            }
            else if(s[i]=='['){
                b2++;
                top++;
                bracket[top]=2;
            }
            else if(s[i]=='{'){
                b3++;
                top++;
                bracket[top]=3;
            }
            else if(s[i]==')'){
                if(top<0 || bracket[top]!=1){
                    return false;
                }
                top--;
                b1--;
            }
            else if(s[i]==']'){
                if(top<0 || bracket[top]!=2){
                    return false;
                }
                top--;
                b2--;
            }
            else if(s[i]=='}'){
                if(top<0 || bracket[top]!=3){
                    return false;
                }
                top--;
                b3--;
            }
        }
        if (b1!=0 || b2!=0 || b3!=0){
            return false;
        }
        else{
            return true;
        }
    }
};