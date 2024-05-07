class Solution {
public:
    string convertToBase7(int num) {
        if(num==0)return string("0");
        bool neg=(num>0?false:true);
        if(neg)num=-num;
        string ans("");
        while(num>0){
            ans+=num%7+'0';
            num=num/7;
        }
        if(neg)ans+='-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};