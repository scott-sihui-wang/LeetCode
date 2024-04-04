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
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int len=arr.size();
        sort(arr,0,len-1);
        if(len==2){
            return true;
        }
        else{
            int diff=arr[1]-arr[0];
            for(int i=2;i<len;i++){
                if(arr[i]-arr[i-1]!=diff){
                    return false;
                }
            }
            return true;
        }
    }
};