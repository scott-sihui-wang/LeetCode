class Solution {
public:
    void findPeak(vector<int>& nums,int begin,int end,vector<int>& ans){
        if(end-begin==1){
            if(nums[end]>nums[begin]){
                if(end==nums.size()-1){
                    ans.push_back(end);
                }
                else if(nums[end]>nums[end+1]){
                    ans.push_back(end);
                }
            }
            else{
                if(begin==0){
                    ans.push_back(begin);
                }
                else if(nums[begin]>nums[begin-1]){
                    ans.push_back(begin);
                }
            }
        }
        else if(end-begin==0){
            if(begin==0){
                if(nums.size()==1){
                    ans.push_back(begin);
                }
                else if(nums[begin+1]<nums[begin]){
                    ans.push_back(begin);
                }
            }
            else if(begin==nums.size()-1){
                if(nums[begin]>nums[begin-1]){
                    ans.push_back(begin);
                }
            }
            else{
                if(nums[begin]>nums[begin+1] && nums[begin]>nums[begin-1]){
                    ans.push_back(begin);
                }
            }
        }
        else if(end>begin){
            int mid=(begin+end)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                ans.push_back(mid);
            }
            else{
                findPeak(nums,begin,mid-1,ans);
                findPeak(nums,mid+1,end,ans);
            }
        }
    }
    int findPeakElement(vector<int>& nums) {
        vector<int> ans;
        findPeak(nums,0,nums.size()-1,ans);
        return ans[0];
    }
};