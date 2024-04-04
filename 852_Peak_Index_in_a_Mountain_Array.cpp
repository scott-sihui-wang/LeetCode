class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int begin=0;
        int end=arr.size()-1;
        while(begin!=end){
            int mid=(begin+end)/2;
            if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
                return mid;
            }
            if(arr[mid+1]>arr[mid]){
                begin=mid+1;
            }
            else if(arr[mid-1]>arr[mid]){
                end=mid;
            }
        }
        return begin;
    }
};