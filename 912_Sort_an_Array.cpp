class Solution {
public:
    int findMax(vector<int>& nums){
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            ans=max(ans,nums[i]);
        }
        return ans;
    }
    void CountSort(vector<int>& nums,int n){
        int output[nums.size()];
        int cnt[10];
        int base=1;
        for(int turns=0;turns<n;turns++){
            memset(cnt,0,sizeof(cnt));
            for(int i=0;i<nums.size();i++){
                cnt[(nums[i]/base)%10]++;
            }
            for(int i=1;i<10;i++){
                cnt[i]+=cnt[i-1];
            }
            for(int i=nums.size()-1;i>=0;i--){
                output[cnt[(nums[i]/base)%10]-1]=nums[i];
                cnt[(nums[i]/base)%10]--;
            }
            for(int i=0;i<nums.size();i++){
                nums[i]=output[i];
            }
            base=base*10;
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i]+=50000;
        }
        int M=findMax(nums);
        int cnt=0;
        while(M>=1){
            M=M/10;
            cnt++;
        }
        CountSort(nums,cnt);
        for(int i=0;i<nums.size();i++){
            nums[i]-=50000;
        }
        return nums;
    }
};