class Solution {
public:
    int str2val(string& s){
        int len=s.length();
        int sgn;
        int start;
        if(s[0]=='-'){
            sgn=-1;
            start=1;
        }
        else{
            sgn=1;
            start=0;
        }
        int val=0;
        for(int i=start;i<len;i++){
            val=val*10+(s[i]-'0');
        }
        val=sgn*val;
        return val;
    }
    int evalRPN(vector<string>& tokens) {
        int val[10000];
        int top=-1;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i].length()==1 && tokens[i][0]=='+'){
                val[top-1]=val[top]+val[top-1];
                top--;
            }
            else if(tokens[i].length()==1 && tokens[i][0]=='-'){
                val[top-1]=val[top-1]-val[top];
                top--;
            }
            else if(tokens[i].length()==1 && tokens[i][0]=='*'){
                val[top-1]=val[top-1]*val[top];
                top--;
            }
            else if(tokens[i].length()==1 && tokens[i][0]=='/'){
                val[top-1]=val[top-1]/val[top];
                top--;
            }
            else{
                val[++top]=str2val(tokens[i]);
            }
        }
        return val[top];
    }
};