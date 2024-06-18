class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans=0;
        int i=0;
        while(i<arr.size()){
            while(i<arr.size() && arr[i]==i){
                ans++;
                i++;
            }
            if(i<arr.size()){
                int minV=arr[i],maxV=arr[i];
                int start=i,end=i;
                while(i<arr.size() && (start!=minV || end!=maxV)){
                    i++;
                    end++;
                    maxV=max(maxV,arr[i]);
                    minV=min(minV,arr[i]);
                }
                ans++;
                i++;
            }
        }
        return ans;
    }
};