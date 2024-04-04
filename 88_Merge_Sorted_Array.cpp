class Solution {
public:
    void sort(vector<int>& arr,int begin,int end){
        if(begin>=end)return;
        int i=begin;
        int j=end;
        int key=arr[begin];
        while(1){
            while(arr[i]<=key){
                i++;
                if(i==end){
                    break;
                }
            }
            while(arr[j]>=key){
                j--;
                if(j==begin){
                    break;
                }
            }
            if(i>=j)break;
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;
        }
        arr[begin]=arr[j];
        arr[j]=key;
        sort(arr,begin,j-1);
        sort(arr,j+1,end);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            nums1[m+i]=nums2[i];
        }
        sort(nums1,0,m+n-1);
    }
};