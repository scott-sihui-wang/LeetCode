class Solution {
public:
    void merge(vector<pair<int,int>>&n,int low,int mid,int high,vector<int>& ans){
        vector<pair<int,int>>tmp(high-low+1);
        int i=low,j=mid+1,ptr=0;
        while(i<=mid && j<=high){
            if(n[i].first>n[j].first){
                tmp[ptr]=n[i];
                ans[n[i].second]+=high-j+1;
                ptr++;
                i++;
            }
            else{
                tmp[ptr]=n[j];
                ptr++;
                j++;
            }
        }
        while(i<=mid){
            tmp[ptr]=n[i];
            ptr++;
            i++;
        }
        while(j<=high){
            tmp[ptr]=n[j];
            ptr++;
            j++;
        }
        for(int i=low;i<=high;i++){
            n[i]=tmp[i-low];
        }
    }
    void mergeSort(vector<pair<int,int>>&n,int low,int high,vector<int>& ans){
        if(low>=high)return;
        int mid=(low+high)/2;
        mergeSort(n,low,mid,ans);
        mergeSort(n,mid+1,high,ans);
        merge(n,low,mid,high,ans);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>>n;
        for(int i=0;i<nums.size();i++){
            n.push_back({nums[i],i});
        }
        vector<int> ans(nums.size());
        mergeSort(n,0,nums.size()-1,ans);
        return ans;
    }
};