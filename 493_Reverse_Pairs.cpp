class Solution {
public:
    void merge(vector<int>& nums, int begin, int end, int& ans){
        int mid=(begin+end)/2;
        int arr1[mid-begin+1], arr2[end-mid];
        for(int i=begin;i<=mid;i++){
            arr1[i-begin]=nums[i];
        }
        for(int i=mid+1;i<=end;i++){
            arr2[i-mid-1]=nums[i];
        }
        int j=0;
        for(int i=0;i<mid-begin+1;i++){
            while(j<end-mid && arr1[i]>2*(long long)arr2[j]){
                j++;
            }
            ans+=j;
        }
        int ptr1=0,ptr2=0,ptr=begin;
        while(ptr1<mid-begin+1 && ptr2<end-mid){
            if(arr1[ptr1]<=arr2[ptr2]){
                nums[ptr]=arr1[ptr1];
                ptr++;
                ptr1++;
            }
            else{
                nums[ptr]=arr2[ptr2];
                ptr++;
                ptr2++;
            }
        }
        while(ptr1<mid-begin+1){
            nums[ptr++]=arr1[ptr1++];
        }
        while(ptr2<end-mid){
            nums[ptr++]=arr2[ptr2++];
        }
    }
    void mergeSort(vector<int>& nums, int begin, int end, int& ans){
        if(begin<end){
            int mid=(begin+end)/2;
            mergeSort(nums,begin,mid,ans);
            mergeSort(nums,mid+1,end,ans);
            merge(nums,begin,end,ans);
        }
    }
    int reversePairs(vector<int>& nums) {
        int ans=0;
        mergeSort(nums,0,nums.size()-1,ans);
        return ans;
    }
};