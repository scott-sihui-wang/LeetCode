class Solution {
public:
    void sort(vector<int>& arr, int begin,int end){
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
    vector<int> sortedSquares(vector<int>& nums) {
        int len=nums.size();
        vector<int> sol(len);
        for(int i=0;i<len;i++){
            sol[i]=nums[i]*nums[i];
        }
        sort(sol,0,len-1);
        return sol;
    }
};