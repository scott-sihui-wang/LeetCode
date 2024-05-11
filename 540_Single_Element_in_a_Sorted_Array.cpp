class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int begin=0,end=nums.size()-1;
        while(begin<=end){
            int mid=(begin+end)/2;
            if(mid%2==0){
                if(mid<nums.size()-1 && nums[mid]==nums[mid+1]){
                    begin=mid+2;
                }
                else if(mid>0 && nums[mid]==nums[mid-1]){
                    end=mid-2;
                }
                else{
                    return nums[mid];
                }
            }
            else{
                if(mid>0 && nums[mid]==nums[mid-1]){
                    begin=mid+1;
                }
                else if(mid<nums.size()-1 && nums[mid]==nums[mid+1]){
                    end=mid-1;
                }
                else{
                    return nums[mid];
                }
            }
        }
        return -1;
    }
};