class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        unordered_map<int,long long>freq[9];
        int cnt=0;
        while(nums[0]!=0){
            for(int i=0;i<nums.size();i++){
                freq[cnt][nums[i]%10]++;
                nums[i]=nums[i]/10;
            }
            cnt++;
        }
        long long ans=0;
        for(int i=0;i<cnt;i++){
            for(int j=0;j<9;j++){
                for(int k=j+1;k<=9;k++){
                    ans+=freq[i][j]*freq[i][k];
                }
            }
        }
        return ans;
    }
};