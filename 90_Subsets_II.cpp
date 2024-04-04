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
    void solve(int item[],int cnt[],int n,int k,int comb[],vector<vector<int> >&sol){
        for(int i=0;i<=cnt[k-1];i++){
            comb[k-1]=i;
            if(k<n){
                solve(item,cnt,n,k+1,comb,sol);
            }
            else{
                vector<int> sub_sol;
                for(int j=0;j<n;j++){
                    for(int k=0;k<comb[j];k++){
                        sub_sol.push_back(item[j]);
                    }
                }
                sol.push_back(sub_sol);
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int len=nums.size();
        sort(nums,0,len-1);
        int item[len];
        int cnt[len];
        int top=0;
        for(int i=0;i<len;i++){
            if(i==0){
                item[top]=nums[i];
                cnt[top++]=1;
            }
            else{
                if(nums[i]==nums[i-1]){
                    cnt[top-1]++;
                }
                else{
                    item[top]=nums[i];
                    cnt[top++]=1;
                }
            }
        }
        vector<vector<int> >sol;
        int comb[top];
        solve(item,cnt,top,1,comb,sol);
        return sol;
    }
};