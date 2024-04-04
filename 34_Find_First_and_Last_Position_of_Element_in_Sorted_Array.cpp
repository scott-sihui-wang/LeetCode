class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> sol(2,-1);
        int len=nums.size();
        if(len==0){
            return sol;
        }
        int begin=0;
        int end=len-1;
        int mid;
        while(begin<end){
            mid=(begin+end)/2;
            if(nums[mid]>=target){
                end=mid;
            }
            else{
                begin=mid+1;
            }
        }
        if(nums[begin]!=target){
            return sol;
        }
        else{
            sol[0]=begin;
        }
        end=len-1;
        while(begin<end){
            mid=(begin+end)/2;
            if(nums[mid]<=target){
                begin=mid+1;
            }
            else{
                end=mid;
            }
        }
        if(nums[end]==target){
            sol[1]=end;
        }
        else{
            sol[1]=end-1;
        }
        return sol;
    }
};