class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans=string("");
        if(a>=b){
            while(a>0 && b>0 && a>b){
                ans+=string(2,'a');
                ans+=string(1,'b');
                a-=2;
                b-=1;
            }
            while(a>0 && b>0){
                ans+=string(1,'a');
                ans+=string(1,'b');
                a--;
                b--;
            }
            if(a>0){
                ans+=string(a,'a');
            }
            return ans;
        }
        else{
            while(a>0 && b>0 && a<b){
                ans+=string(2,'b');
                ans+=string(1,'a');
                a-=1;
                b-=2;
            }
            while(a>0 && b>0){
                ans+=string(1,'b');
                ans+=string(1,'a');
                a--;
                b--;
            }
            if(b>0){
                ans+=string(b,'b');
            }
            return ans;
        }
    }
};