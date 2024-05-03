class Solution {
public:
    string toHex(int num) {
        char HexDigits[16]={'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if(num==0)return string(1,HexDigits[0]);
        if(num>0){
            string ans("");
            while(num>0){
                ans=HexDigits[num%16]+ans;
                num/=16;
            }
            return ans;
        }
        else{
            int inv=-1-num;
            if(inv==0)return string("ffffffff");
            string ans("");
            while(inv>0){
                ans=HexDigits[15-inv%16]+ans;
                inv/=16;
            }
            if(ans.size()<8){
                ans=string(8-ans.size(),'f')+ans;
            }
            return ans;
        }
    }
};