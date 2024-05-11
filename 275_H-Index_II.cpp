class Solution {
public:
    int hIndex(vector<int>& citations) {
        int begin=0,end=citations.size()-1,n=citations.size();
        while(begin<=end){
            int mid=(begin+end)/2;
            if(citations[mid]>=n-mid){
                end=mid-1;
            }
            else{
                begin=mid+1;
            }
        }
        return n-begin;
    }
};