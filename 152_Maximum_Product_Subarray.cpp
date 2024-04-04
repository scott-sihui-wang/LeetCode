class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz=nums.size();
        int ans;
        int dp_pos[sz],dp_neg[sz];
        bool init_pos[sz],init_neg[sz];
        memset(init_pos,false,sizeof(init_pos));
        memset(init_neg,false,sizeof(init_neg));
        if(nums[sz-1]>0){
            dp_pos[sz-1]=nums[sz-1];
            init_pos[sz-1]=true;
        }
        else if(nums[sz-1]<0){
            dp_neg[sz-1]=nums[sz-1];
            init_neg[sz-1]=true;
        }
        else{
            dp_pos[sz-1]=nums[sz-1];
            dp_neg[sz-1]=nums[sz-1];
            init_pos[sz-1]=true;
            init_neg[sz-1]=true;
        }
        ans=nums[sz-1];
        for(int i=sz-2;i>=0;i--){
            if(nums[i]>0){
                dp_pos[i]=nums[i];
                init_pos[i]=true;
                if(init_pos[i+1]==true){
                    dp_pos[i]=max(dp_pos[i],dp_pos[i]*dp_pos[i+1]);
                }
                if(init_neg[i+1]==true){
                    dp_neg[i]=nums[i]*dp_neg[i+1];
                    init_neg[i]=true;
                }
            }
            else if(nums[i]<0){
                dp_neg[i]=nums[i];
                init_neg[i]=true;
                if(init_pos[i+1]==true){
                    dp_neg[i]=min(dp_neg[i],dp_neg[i]*dp_pos[i+1]);
                }
                if(init_neg[i+1]==true){
                    dp_pos[i]=nums[i]*dp_neg[i+1];
                    init_pos[i]=true;
                }
            }
            else{
                dp_pos[i]=0;
                dp_neg[i]=0;
                init_pos[i]=true;
                init_neg[i]=true;
            }
            if(init_pos[i]==true){
                ans=max(ans,dp_pos[i]);
            }
            /*if(ans>0 && init_pos[i]==true){
                ans=max(ans,dp_pos[i]);
            }
            else if(ans<0 && init_neg[i]==true){
                ans=ans*dp_neg[i];
            }
            else if(ans==0 && init_pos[i]==true){
                ans=dp_pos[i];
            }*/
        }
        return ans;
    }
};