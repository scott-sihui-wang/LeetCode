class Solution {
public:
    int search_min(vector<int>& nums,int begin,int end){
        while(begin<end-1){
            if(nums[begin]<nums[end])return begin;
            int mid=(begin+end)/2;
            if(nums[mid]<nums[begin]){
                return search_min(nums,begin,mid);      
            }
            else if(nums[mid]>nums[begin]){
                return search_min(nums,mid+1,end);
            }
            else{
                int s1=search_min(nums,begin,mid);
                int s2=search_min(nums,mid+1,end);
                return nums[s2]>=nums[s2-1]?s1:s2;
            }
        }
        return (nums[begin]>nums[end]?end:begin);
    }
    bool binarySearch(vector<int>& nums, int target, int begin, int end){
        if(begin<end){
            int mid=(begin+end)/2;
            if(target==nums[mid]){
                return true;
            }
            else if(target>nums[mid]){
                return binarySearch(nums,target,mid+1,end);
            }
            else{
                return binarySearch(nums,target,begin,mid-1);
            }
        }
        else{
            return target==nums[begin];
        }
    }
    bool search(vector<int>& nums, int target) {
        int len=nums.size();
        int s=search_min(nums,0,len-1);
        if(s==0){
            return binarySearch(nums,target,0,len-1);
        }
        else if(target>=nums[s] && target<=nums[len-1]){
            return binarySearch(nums,target,s,len-1);
        }
        else if(target>=nums[0] && target<=nums[s-1]){
            return binarySearch(nums,target,0,s-1);
        }
        else{
            return false;
        }
    }
};