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
    void nextPermutation(vector<int>& nums) {
        int len=nums.size();
        int i=len-1;
        while(i>0 && nums[i-1]>=nums[i]){
            i--;
        }
        if(i==0){
            for(int i=0;i<len/2;i++){
                int tmp=nums[i];
                nums[i]=nums[len-1-i];
                nums[len-1-i]=tmp;
            }
        }
        else{
            int min_val=INT_MAX;
            int min_idx;
            for(int j=i;j<len;j++){
                if(nums[j]>nums[i-1] && nums[j]<min_val){
                    min_val=nums[j];
                    min_idx=j;
                }
            }
            int tmp=nums[i-1];
            nums[i-1]=nums[min_idx];
            nums[min_idx]=tmp;
            sort(nums,i,len-1);
        }
    }
};