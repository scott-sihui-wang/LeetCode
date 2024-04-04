class Solution {
public:
    int romanToInt(string s) {
        int len=s.length();
        int idx=0;
        int num=0;
        while(idx<len){
            if(s[idx]=='I'){
                if(s[idx+1]=='V'){
                    num+=4;
                    idx+=2;
                }
                else if(s[idx+1]=='X'){
                    num+=9;
                    idx+=2;
                }
                else{
                    num+=1;
                    idx+=1;
                }
            }
            else if(s[idx]=='V'){
                num+=5;
                idx+=1;
            }
            else if(s[idx]=='X'){
                if(s[idx+1]=='L'){
                    num+=40;
                    idx+=2;
                }
                else if(s[idx+1]=='C'){
                    num+=90;
                    idx+=2;
                }
                else{
                    num+=10;
                    idx+=1;
                }
            }
            else if(s[idx]=='L'){
                num+=50;
                idx+=1;
            }
            else if(s[idx]=='C'){
                if(s[idx+1]=='D'){
                    num+=400;
                    idx+=2;
                }
                else if(s[idx+1]=='M'){
                    num+=900;
                    idx+=2;
                }
                else{
                    num+=100;
                    idx+=1;
                }
            }
            else if(s[idx]=='D'){
                num+=500;
                idx+=1;
            }
            else if(s[idx]=='M'){
                num+=1000;
                idx+=1;
            }
        }
        return num;
    }
};