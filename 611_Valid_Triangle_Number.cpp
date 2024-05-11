class Solution {
public:
    int binarySearch(vector<int>& nums,int begin,int end,long long bound){
        while(begin<=end){
            int mid=(begin+end)/2;
            if(nums[mid]>=bound){
                end=mid-1;
            }
            else{
                begin=mid+1;
            }
        }
        return begin;
    }
    int triangleNumber(vector<int>& nums) {
        if(nums.size()<3)return 0;
        sort(nums.begin(),nums.end());
        int cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            for(int j=i+1;j<nums.size()-1;j++){
                cnt+=binarySearch(nums,j+1,nums.size()-1,nums[i]+nums[j])-j-1;
            }
        }
        return cnt;
    }
};