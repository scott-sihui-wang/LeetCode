class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long ans=INT_MAX;
        for(int i=0;i<nums.size()-2;i++){
            int low=i+1,high=nums.size()-1;
            while(low<high){
                long long tar=(long long)target-(long long)nums[i];
                if((long long)nums[low]+(long long)nums[high]<tar){
                    if(abs((long long)ans-(long long)target)>abs((long long)nums[i]+(long long)nums[low]+(long long)nums[high]-(long long)target)){
                        ans=(long long)nums[i]+(long long)nums[low]+(long long)nums[high];
                    }
                    low++;
                }
                else if((long long)nums[low]+(long long)nums[high]>tar){
                    if(abs((long long)ans-(long long)target)>abs((long long)nums[i]+(long long)nums[low]+(long long)nums[high]-(long long)target)){
                        ans=(long long)nums[i]+(long long)nums[low]+(long long)nums[high];
                    }
                    high--;
                }
                else{
                    return target;
                }
            }
        }
        return (int)ans;
    }
