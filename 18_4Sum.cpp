class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int i=0;
        int n=nums.size();
        while(i<n-3){
            int j=i+1;
            while(j<n-2){
                long long tar=(long long)target-(long long)nums[i]-(long long)nums[j];
                int low=j+1,high=n-1;
                while(low<high){
                    if((long long)nums[low]+(long long)nums[high]<tar){
                        low++;
                    }
                    else if((long long)nums[low]+(long long)nums[high]>tar){
                        high--;
                    }
                    else{
                        ans.push_back({nums[i],nums[j],nums[low],nums[high]});
                        do{
                            ++low;
                        }while(low<n && nums[low-1]==nums[low]);
                        do{
                            --high;
                        }while(high>j && nums[high+1]==nums[high]);
                    }
                }
                do{
                    ++j;
                }while(j<n-2 && nums[j-1]==nums[j]);
            }
            do{
                ++i;
            }while(i<n-3 && nums[i-1]==nums[i]);
        }
        return ans;
    }
};