class Solution {
public:
    int convertTime(string current, string correct) {
        int h1=(current[0]-'0')*10+(current[1]-'0');
        int h2=(correct[0]-'0')*10+(correct[1]-'0');
        int m1=(current[3]-'0')*10+(current[4]-'0');
        int m2=(correct[3]-'0')*10+(correct[4]-'0');
        int diff;
        if(h1<h2){
            diff=(h2-h1)*60+m2-m1;
        }
        else if(h1>h2){
            diff=(h1-h2)*60+m1-m2;
        }
        else{
            diff=abs(m1-m2);
        }
        int sol=0;
        sol+=diff/60;
        diff=diff%60;
        sol+=diff/15;
        diff=diff%15;
        sol+=diff/5;
        diff=diff%5;
        sol+=diff;
        return sol;
    }
};