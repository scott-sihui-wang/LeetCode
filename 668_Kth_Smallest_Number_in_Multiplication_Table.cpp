class Solution {
public:
    int count(int m,int n, int bound){
        int ans=0;
        for(int i=1;i<=m;i++){
            ans+=min(bound/i,n);
        }
        return ans;
    }
    int findKthNumber(int m, int n, int k) {
        int begin=1,end=m*n;
        while(begin<=end){
            int mid=(begin+end)/2;
            if(count(m,n,mid)<k){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return begin;
    }
};