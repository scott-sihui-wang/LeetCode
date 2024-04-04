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
    void solve(int num[],int freq[],int len,int n,int cur,int path[],vector<vector<int> >&sol){
        for(int i=0;i<len;i++){
            if(freq[i]>0){
                freq[i]--;
                path[cur-1]=num[i];
                if(cur<n){
                    solve(num,freq,len,n,cur+1,path,sol);
                }
                else if(cur==n){
                    vector<int> sub_sol;
                    for(int j=0;j<n;j++){
                        sub_sol.push_back(path[j]);
                    }
                    sol.push_back(sub_sol);
                }
                freq[i]++;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len=nums.size();
        sort(nums,0,len-1);
        int i=0;
        int benchmark;
        int idx;
        int num[len];
        int freq[len];
        int path[len];
        int top=-1;
        while(i<len){
            benchmark=nums[i];
            idx=i;
            while(i<len && nums[i]==benchmark){
                i++;
            }
            num[++top]=benchmark;
            freq[top]=i-idx;
        }
        vector<vector<int> >sol;
        solve(num,freq,top+1,len,1,path,sol);
        return sol;
    }
};