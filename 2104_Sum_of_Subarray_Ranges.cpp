class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int len=nums.size();
        if(len==1)return 0;
        int arr_min[len];
        int arr_max[len];
        for(int i=0;i<len;i++){
            arr_min[i]=nums[i];
            arr_max[i]=nums[i];
        }
        long long sum=0;
        for(int i=2;i<=len;i++){
            for(int j=0;j<=len-i;j++){
                arr_min[j]=min(arr_min[j],arr_min[j+1]);
                arr_max[j]=max(arr_max[j],arr_max[j+1]);
                sum+=arr_max[j]-arr_min[j];
            }
        }
        return sum;
    }
};