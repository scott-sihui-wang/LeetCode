class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        long long ans=0;
        int left_LE=-1,right_LE=-1,left_E=-1,right_E=-1;
        vector<vector<int>>intervals;
        int i=0;
        for(;i<nums.size();i++){
            if(nums[i]<=right){
                if(left_LE==-1){
                    left_LE=i;
                    intervals.clear();
                }
                if(nums[i]>=left && left_E==-1){
                    left_E=i;
                }
                else if(nums[i]<left && left_E!=-1){
                    right_E=i-1;
                    intervals.push_back({left_E,right_E});
                    left_E=-1;
                    right_E=-1;
                }
            }
            else{
                if(left_E!=-1){
                    right_E=i-1;
                    intervals.push_back({left_E,right_E});
                    left_E=-1;
                    right_E=-1;
                }
                if(left_LE!=-1){
                    right_LE=i-1;
                    for(int j=0;j<intervals.size();j++){
                        ans+=(2LL*right_LE+2-intervals[j][0]-intervals[j][1])*(intervals[j][1]-intervals[j][0]+1)/2;
                        if(j==0){
                            ans+=(right_LE-intervals[0][0]+1)*(intervals[0][0]-left_LE);
                        }
                        else{
                            ans+=(right_LE-intervals[j][0]+1)*(intervals[j][0]-intervals[j-1][1]-1);
                        }
                    }
                    intervals.clear();
                    left_LE=-1;
                    right_LE=-1;
                }
            }
        }
        if(left_E!=-1){
            right_E=i-1;
            intervals.push_back({left_E,right_E});
            left_E=-1;
            right_E=-1;
        }
        if(left_LE!=-1){
            right_LE=i-1;
            for(int j=0;j<intervals.size();j++){
                ans+=(2LL*right_LE+2-intervals[j][0]-intervals[j][1])*(intervals[j][1]-intervals[j][0]+1)/2;
                if(j==0){
                    ans+=(right_LE-intervals[0][0]+1)*(intervals[0][0]-left_LE);
                }
                else{
                    ans+=(right_LE-intervals[j][0]+1)*(intervals[j][0]-intervals[j-1][1]-1);
                }
            }
            intervals.clear();
            left_LE=-1;
            right_LE=-1;
        }
        return ans;
    }
};