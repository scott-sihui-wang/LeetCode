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
            if(i>=j){
                break;
            }
            int tmp=nums[i];
            nums[i]=nums[j];
            nums[j]=tmp;
        }
        nums[begin]=nums[j];
        nums[j]=key;
        sort(nums,begin,j-1);
        sort(nums,j+1,end);
    }
    int countElements(vector<int>& nums) {
        int len=nums.size()-1;
        sort(nums,0,len);
        int minimum=nums[0];
        int maximum=nums[len];
        int cnt=0;
        for(int i=1;i<len;i++){
            if(nums[i]>minimum && nums[i]<maximum){
                ++cnt;
            }
        }
        return cnt;
    }
};