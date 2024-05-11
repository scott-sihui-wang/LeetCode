class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        double left=0.0,right=1.0;
        while(left<=right){
            double mid=(left+right)/2.0;
            int j=1;
            int cnt=0;
            double max_ratio=0.0;
            int idx_i=0,idx_j=0;
            for(int i=0;i<arr.size()-1;i++){
                while(j<arr.size() && 1.0*arr[i]>=mid*arr[j]){
                    j++;
                }
                if(j==arr.size()){
                    break;
                }
                cnt+=arr.size()-j;
                if(arr[i]*1.0/arr[j]>max_ratio){
                    max_ratio=arr[i]*1.0/arr[j];
                    idx_i=i;
                    idx_j=j;
                }
            }
            if(cnt==k){
                return {arr[idx_i],arr[idx_j]};
            }
            else if(cnt<k){
                left=mid;
            }
            else{
                right=mid;
            }
        }
        return {};        
    }
};