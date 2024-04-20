class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sz=nums.size();
        int pf[sz+1];
        int sum=0;
        pf[0]=0;
        for(int i=0;i<sz;i++){
            sum+=nums[i];
            pf[i+1]=sum;
        }
        int idx=0;
        int l,r;
        for(;idx<sz;idx++){
            l=pf[idx];
            r=pf[sz]-pf[idx+1];
            if(l==r){
                break;
            }
        }
        return (l==r)?idx:-1;
    }
};