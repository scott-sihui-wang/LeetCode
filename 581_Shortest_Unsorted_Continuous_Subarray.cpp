class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int pgl[n],nsr[n];
        for(int i=0;i<n;i++){
            pgl[i]=-1;
            for(int j=0;j<i;j++){
                if(nums[j]>nums[i]){
                    pgl[i]=j;
                    break;
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            nsr[i]=-1;
            for(int j=n-1;j>i;j--){
                if(nums[j]<nums[i]){
                    nsr[i]=j;
                    break;
                }
            }
        }
        int pgl_m=n,nsr_M=-1;
        for(int i=0;i<n;i++){
            if(pgl[i]!=-1){
                pgl_m=min(pgl_m,pgl[i]);
            }
            if(nsr[i]!=-1){
                nsr_M=max(nsr_M,nsr[i]);
            }
        }
        if(pgl_m!=n && nsr_M!=-1){
            return nsr_M-pgl_m+1;
        }
        else{
            return 0;
        }
    }
};