class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum=0;
        int len=arr.size();
        for(int i=0;i<=(len-1)/2;i++){
            for(int j=0;j<len-2*i;j++){
                for(int k=0;k<2*i+1;k++){
                    sum+=arr[j+k];
                }
            }
        }
        return sum;
    }
};