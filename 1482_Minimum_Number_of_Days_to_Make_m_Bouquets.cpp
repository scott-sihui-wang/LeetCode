class Solution {
public:
    int numBouquets(vector<int>& bloomDay, int k, int day){
        int cnt=0;
        int ans=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
                if(cnt==k){
                    cnt=0;
                    ans++;
                }
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long)m*k>(long long)bloomDay.size()){
            return -1;
        }
        int end=INT_MIN,start=INT_MAX;
        for(int i=0;i<bloomDay.size();i++){
            end=max(end,bloomDay[i]);
            start=min(start,bloomDay[i]);
        }
        int ans;
        while(start<=end){
            int mid=(start+end)/2;
            int res=numBouquets(bloomDay,k,mid);
            if(res>=m){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};