class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int begin=0,end=nums.size()-1;
        while(begin<=end){
            int mid=(begin+end)/2;
            if(nums[mid]<=0){
                begin=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        int first_non_pos=end;
        int pos3=INT_MIN,pos1_neg2=INT_MIN,pos2_neg1=INT_MIN,neg3=INT_MIN;
        if(nums[nums.size()-3]>0){
            pos3=nums[nums.size()-1]*nums[nums.size()-2]*nums[nums.size()-3];
        }
        if(nums[nums.size()-1]>0 && first_non_pos>=1){
            pos1_neg2=nums[nums.size()-1]*nums[0]*nums[1];
        }
        if(pos3!=INT_MIN || pos1_neg2!=INT_MIN){
            return max(pos3,pos1_neg2);
        }
        if(nums[first_non_pos]==0){
            return 0;
        }
        if(first_non_pos<nums.size()-2){
            pos2_neg1=nums[first_non_pos+1]*nums[first_non_pos+2]*nums[first_non_pos];
        }
        neg3=nums[first_non_pos]*nums[first_non_pos-1]*nums[first_non_pos-2];
        return max(pos2_neg1,neg3);
    }
};