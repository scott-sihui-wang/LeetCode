class Solution {
public:
    bool isPerfectSquare(int num) {
        long long begin=1;
        long long end=1;
        end=end<<16;
        while(begin!=end){
            long long mid=(begin+end)/2;
            long long tmp=mid*mid;
            if(tmp==num){
                return mid;
            }
            if(num<tmp){
                end=mid;
            }
            else if(num>tmp){
                begin=mid+1;
            }
        }
        if(begin*begin==num){
            return true;
        }
        else{
            return false;
        }
    }
};