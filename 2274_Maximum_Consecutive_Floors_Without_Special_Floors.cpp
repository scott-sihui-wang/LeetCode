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
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int len=special.size();
        sort(special,0,len-1);
        int max_val=0;
        int diff;
        for(int i=0;i<=len;i++){
            if(i==0){
                diff=special[i]-bottom;
            }
            else if(i==len){
                diff=top-special[i-1];
            }
            else{
                diff=special[i]-special[i-1]-1;
            }
            max_val=max(max_val,diff);
        }
        return max_val;
    }
};