class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long a=0;a*a<=(c+1)/2;a++){
            double b=sqrt(c-a*a);
            if(b==(int)b)return true;
        }
        return false;
    }
};