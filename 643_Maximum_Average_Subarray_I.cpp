class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maximum=sum;
        for(int i=k;i<nums.size();i++){
            sum+=nums[i]-nums[i-k];;
            maximum=max(maximum,sum);
        }
        return 1.0*maximum/k;
    }
};