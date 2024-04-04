class Solution {
public:
    string removeOuterParentheses(string s) {
        int len=s.length();
        int val=0;
        int skip_list[100000];
        int top=0;
        for(int i=0;i<len;i++){
            if(s[i]=='('){
                val++;
                if(val==1){
                    skip_list[top++]=i;
                }
            }
            else if(s[i]==')'){
                val--;
                if(val==0){
                    skip_list[top++]=i;
                }
            }
        }
        if(top==0){
            return s;
        }
        else{
            int cnt=0;
            char sol[len];
            for(int i=0;i<skip_list[0];i++){
                sol[cnt++]=s[i];
            }
            for(int i=0;i<top-1;i++){
                for(int j=skip_list[i]+1;j<skip_list[i+1];j++){
                    sol[cnt++]=s[j];
                }
            }
            for(int i=skip_list[top-1]+1;i<len;i++){
                sol[cnt++]=s[i];
            }
            sol[cnt]='\0';
            return string(sol);
        }
    }
};