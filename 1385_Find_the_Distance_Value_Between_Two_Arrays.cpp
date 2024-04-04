class Solution {
public:
    void sort(vector<int>& arr,int begin,int end){
        if(begin>=end) return;
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
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int len1=arr1.size();
        int len2=arr2.size();
        sort(arr1,0,len1-1);
        sort(arr2,0,len2-1);
        int cnt=0;
        int begin=0;
        int end;
        for(int i=0;i<len1;i++){
            end=len2-1;
            if(arr1[i]<arr2[begin]){
                if(d<arr2[begin]-arr1[i]){
                    cnt++;
                }
                continue;
            }
            else if(arr1[i]>arr2[end]){
                if(d<arr1[i]-arr2[end]){
                    cnt++;
                }
                begin=end;
                continue;
            }
            while(begin!=end){
                int mid=(begin+end)/2;
                if(arr2[mid]==arr1[i]){
                    begin=mid;
                    break;
                }
                if(arr2[mid]<arr1[i]){
                    begin=mid+1;
                }
                else if(arr2[mid]>arr1[i]){
                    end=mid;
                }
            }
            if(arr2[begin]==arr1[i]){
                if(d<0){
                    cnt++;
                }
            }
            else{
                if(d<min(arr2[begin]-arr1[i],arr1[i]-arr2[begin-1])){
                    cnt++;
                }
                begin--;
            }
        }
        return cnt;
    }
};