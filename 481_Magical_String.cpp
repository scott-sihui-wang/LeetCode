class Solution {
public:
    int magicalString(int n) {
        string str(n,' ');
        str[0]='1';
        int cnt_1=1,cnt_2=0;
        bool isOne=true;
        int ptr=0,gen=1;
        int cnt=1;
        while(gen<n){
            if((isOne && str[ptr]-'0'==cnt_1) || (!isOne && str[ptr]-'0'==cnt_2)){
                isOne=!isOne;
                if(isOne){
                    cnt++;
                    str[gen]='1';
                    cnt_1=1;
                    cnt_2=0;
                }
                else{
                    str[gen]='2';
                    cnt_1=0;
                    cnt_2=1;
                }
                ptr++;
                gen++;
            }
            else{
                if(isOne){
                    cnt++;
                    str[gen]='1';
                    cnt_1++;
                }
                else{
                    str[gen]='2';
                    cnt_2++;
                }
                gen++;
            }
        }
        return cnt;
    }
};