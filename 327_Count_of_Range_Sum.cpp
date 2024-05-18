class Solution {
public:
    void mergeSort(vector<long long>& pf, int l, int m, int r){
        vector<long long>tmp(r-l+1);
        int i=l,j=m+1,k=0;
        while(i<=m && j<=r){
            if(pf[i]<pf[j]){
                tmp[k]=pf[i];
                k++;
                i++;
            }
            else{
                tmp[k]=pf[j];
                k++;
                j++;
            }
        }
        while(i<=m){
            tmp[k]=pf[i];
            i++;
            k++;
        }
        while(j<=r){
            tmp[k]=pf[j];
            j++;
            k++;
        }
        for(int i=l;i<=r;i++){
            pf[i]=tmp[i-l];
        }
    }
    int count(vector<long long>& pf,int l,int r,int lower,int upper){
        if(l==r){
            return (pf[l]>=lower && pf[l]<=upper)?1:0;
        }
        int m=(l+r)/2;
        int cnt_l=count(pf,l,m,lower,upper);
        int cnt_r=count(pf,m+1,r,lower,upper);
        int cnt_lr=0;
        int j=m+1,k=m+1;
        for(int i=l;i<=m;i++){
            while(j<=r && pf[j]<pf[i]+lower){
                j++;
            }
            while(k<=r && pf[k]<=pf[i]+upper){
                k++;
            }
            cnt_lr+=k-j;
        }
        mergeSort(pf,l,m,r);
        return cnt_l+cnt_r+cnt_lr;
    }
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long>pf(nums.size(),0);
        pf[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pf[i]=pf[i-1]+nums[i];
        }
        return count(pf,0,pf.size()-1,lower,upper);
    }
};