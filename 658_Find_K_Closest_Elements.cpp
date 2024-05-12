class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int lower=0,upper=arr.size()-1;
        int range_L,range_H;
        while(lower<=upper){
            int mid=(lower+upper)/2;
            if(arr[mid]>=x){
                upper=mid-1;
            }
            else{
                lower=mid+1;
            }
        }
        range_H=lower;
        lower=0;
        upper=arr.size()-1;
        while(lower<=upper){
            int mid=(lower+upper)/2;
            if(arr[mid]<=x){
                lower=mid+1;
            }
            else{
                upper=mid-1;
            }
        }
        range_L=upper;
        int up=0,down=0;
        if(range_L>=0 && range_L<arr.size() && range_H>=0 && range_H<arr.size() && arr[range_L]==arr[range_H]){
            int l=min(range_L,range_H);
            int u=max(range_L,range_H);
            if(k<=u-l+1){
                return vector<int>(k,arr[range_L]);
            }
            else{
                range_L=l;
                range_H=u;
                ans=vector<int>(u-l+1,arr[range_L]);
                k-=u-l+1;
                up++;
                down++;
            }
        }
        while(range_L-down>=0 && range_H+up<arr.size() && k>0){
            if(arr[range_H+up]-x<x-arr[range_L-down]){
                ans.push_back(arr[range_H+up]);
                up++;
            }
            else{
                ans.push_back(arr[range_L-down]);
                down++;
            }
            k--;
        }
        while(range_L-down>=0 && k>0){
            ans.push_back(arr[range_L-down]);
            down++;
            k--;
        }
        while(range_H+up<arr.size() && k>0){
            ans.push_back(arr[range_H+up]);
            up++;
            k--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};