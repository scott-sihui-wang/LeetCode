class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)return 9;
        long long left_max=pow(10,n)-1, left_min=pow(10,n-1);
        for(long long left=left_max;left>=left_min;left--){
            long long pal=left,r=0;
            for(long long i=left;i!=0;r=r*10+(i%10),i=i/10,pal=pal*10)
                ;
            pal+=r;
            for(long long i=left_max;i>=sqrt(pal);i--){
                if(pal%i==0)return pal%1337;
            }
        }
        return -1;
    }
};