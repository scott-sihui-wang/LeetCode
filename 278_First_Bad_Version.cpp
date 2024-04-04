// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long begin=1;
        long long end=n;
        long long mid;
        while(begin!=end){
            mid=(begin+end)/2;
            if(isBadVersion(mid)==true){
                end=mid;
            }
            else{
                begin=mid+1;
            }
        }
        return begin;
    }
};