class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long m1=(long long)INT_MIN-1,m2=(long long)INT_MIN-1,m3=(long long)INT_MIN-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>m1){
                m3=m2;
                m2=m1;
                m1=nums[i];
            }
            else if(nums[i]<m1 && nums[i]>m2){
                m3=m2;
                m2=nums[i];
            }
            else if(nums[i]<m2 && nums[i]>m3){
                m3=nums[i];
            }
        }
        if(m3<(long long)INT_MIN){
            return m1;
        }
        else{
            return m3;
        }
    }
};