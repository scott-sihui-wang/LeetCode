class Solution {
public:
    int arrangeCoins(int n) {
        long long low=1,high=1<<16;
        while(low<high){
            long long mid=(low+high)/2;
            if(mid*(mid+1)/2<n){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        if(low*(low+1)/2==n){
            return (int)low;
        }
        else{
            return (int)(low-1);
        }
    }
};