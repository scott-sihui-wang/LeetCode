class Solution {
public:
    bool feasible(vector<int>& nums,int k,int m){
        int cnt=0,sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum>m){
                sum=nums[i];
                cnt++;
            }
        }
        cnt++;
        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int m_val=0,M_val=0;
        for(int i=0;i<n;i++){
            m_val=max(m_val,nums[i]);
            M_val+=nums[i];
        }
        int ans=M_val;
        while(m_val<=M_val){
            int mid=(m_val+M_val)/2;
            if(feasible(nums,k,mid)){
                ans=min(ans,mid);
                M_val=mid-1;
            }
            else{
                m_val=mid+1;
            }
        }
        return ans;
    }
};