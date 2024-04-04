class Solution {
public:
    void sort(vector<int>& nums,int begin,int end){
        if(begin>=end)return;
        int i=begin;
        int j=end;
        int key=nums[begin];
        while(1){
            while(nums[i]<=key){
                i++;
                if(i==end){
                    break;
                }
            }
            while(nums[j]>=key){
                j--;
                if(j==begin){
                    break;
                }
            }
            if(i>=j)break;
            int tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
        }
        nums[begin]=nums[j];
        nums[j]=key;
        sort(nums,begin,j-1);
        sort(nums,j+1,end);
    }
    int largestPerimeter(vector<int>& nums) {
        int len=nums.size();
        sort(nums,0,len-1);
        for(int i=len-3;i>=0;i--){
            if(nums[i]+nums[i+1]>nums[i+2]){
                return nums[i]+nums[i+1]+nums[i+2];
            }
        }
        return 0;
    }
};