class Solution {
public:
    int binary_search(vector<int>& nums, int begin, int end, int target){
        while(begin<=end){
            int mid=(begin+end)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target<nums[mid]){
                end=mid-1;
            }
            else if(target>nums[mid]){
                begin=mid+1;
            }
        }
        return -1;
    }
    int search_max(vector<int>& nums){
        if(nums[0]>nums[1]){
            return 0;
        }
        int begin=0;
        int end=nums.size()-1;
        while(begin<end-1){
            int mid=(begin+end)/2;
            if(nums[mid]>nums[0]){
                begin=mid;
            }
            else if(nums[mid]<nums[0]){
                end=mid-1;
            }
        }
        return nums[end]>nums[begin]?end:begin;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            if(nums[0]==target){
                return 0;
            }
            else{
                return -1;
            }
        }
        if(nums[0]<nums[n-1]){
            return binary_search(nums,0,n-1,target);
        }
        else{
            int peak=search_max(nums);
            if(target>=nums[0] && target<=nums[peak]){
                return binary_search(nums,0,peak,target);
            }
            else if(target>=nums[peak+1] && target<=nums[n-1]){
                return binary_search(nums,peak+1,n-1,target);
            }
            else{
                return -1;
            }
        }
    }
};