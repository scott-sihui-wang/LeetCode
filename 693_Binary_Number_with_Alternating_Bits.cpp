class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool valid=true;
        int prev_bit=n%2;
        n=n/2;
        while(n>0){
            if(n%2==prev_bit){
                return false;
            }
            else{
                prev_bit=n%2;
            }
            n=n/2;
        }
        return true;
    }
};