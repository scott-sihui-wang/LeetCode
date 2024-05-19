class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n=num.size();
        if(n<3)return false;
        int i_upper=(num[0]=='0')?1:n-2;
        for(int i=1;i<=i_upper;i++){
            int j_upper=(num[i]=='0')?1:n-i-1;
            for(int j=1;j<=j_upper;j++){
                string opr1=num.substr(0,i),opr2=num.substr(i,j);
                string sum=to_string(stoll(opr1)+stoll(opr2));
                string rest=num.substr(i+j);
                while(sum.size()<=rest.size() && sum==rest.substr(0,sum.size())){
                    if(sum.size()==rest.size())return true;
                    rest=rest.substr(sum.size());
                    opr1=opr2;
                    opr2=sum;
                    sum=to_string(stoll(opr1)+stoll(opr2));
                }
            }
        }
        return false;
    }
};