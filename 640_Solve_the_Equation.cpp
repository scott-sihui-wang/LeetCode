class Solution {
public:
    string solveEquation(string equation) {
        int x_left=0,x_right=0,v_left=0,v_right=0;
        bool leftPart=true;
        bool sign=(equation[0]=='-'?false:true);
        int i=(equation[0]=='-'?1:0);
        while(i<equation.size()){
            bool containNum=false;
            int num=0;
            while(i<equation.size() && equation[i]>='0' && equation[i]<='9'){
                containNum=true;
                num=num*10+equation[i]-'0';
                i++;
            }
            if(containNum && sign==false)num=-num;
            bool containX=(i<equation.size() && equation[i]=='x');
            if(containX)i++;
            if(containNum && containX){
                if(leftPart){
                    x_left+=num;
                }
                else{
                    x_right+=num;
                }
            }
            else if(containNum && !containX){
                if(leftPart){
                    v_left+=num;
                }
                else{
                    v_right+=num;
                }
            }
            else if(!containNum && containX){
                if(leftPart){
                    x_left+=(sign?1:-1);
                }
                else{
                    x_right+=(sign?1:-1);
                }
            }
            if(i<equation.size()){
                if(equation[i]=='='){
                    leftPart=false;
                    if(equation[i+1]=='-'){
                        sign=false;
                        i=i+2;
                    }
                    else{
                        sign=true;
                        i=i+1;
                    }
                }
                else if(equation[i]=='+'){
                    sign=true;
                    i++;
                }
                else if(equation[i]=='-'){
                    sign=false;
                    i++;
                }
            }
        }
        int x=x_left-x_right,v=v_left-v_right;
        if(x==0 && v==0){
            return string("Infinite solutions");
        }
        else if(x==0 && v!=0){
            return string("No solution");
        }
        else{
            return string("x=")+to_string(-v/x);
        }
    }
};