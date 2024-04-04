class Solution {
public:
    int mySqrt(int x) {
        long long begin=1;
        long long end=1;
        end=end<<16;
        while(begin!=end){
            long long mid=(begin+end)/2;
            long long tmp=mid*mid;
            if(tmp==x){
                return mid;
            }
            if(tmp>x){
                end=mid;
            }
            else if(tmp<x){
                begin=mid+1;
            }
        }
        if(begin*begin>x){
            return begin-1;
        }
        else{
            return begin;
        }
    }
};