class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin=0;
        int end=nums.size()-1;
        if(target>nums[end] || target<nums[0])return -1;
        while(begin!=end){
            int mid=(begin+end)/2;
            if(target==nums[mid]){
                return mid;
            }
            if(target<nums[mid]){
                end=mid;
            }
            else if(target>nums[mid]){
                begin=mid+1;
            }
        }
        if(target==nums[begin]){
            return begin;
        }
        else{
            return -1;
        }
    }
};