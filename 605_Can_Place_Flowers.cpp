class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz=flowerbed.size();
        int place[sz];
        memset(place,0,sizeof(place));
        for(int i=0;i<sz;i++){
            if(flowerbed[i]==1){
                place[i]=1;
                if(i-1>=0){
                    place[i-1]=1;
                }
                if(i+1<sz){
                    place[i+1]=1;
                }
            }
        }
        int idx=0;
        int ans=0;
        while(idx<sz){
            while(idx<sz && place[idx]==1){
                idx++;
            }
            if(idx<sz){
                int start=idx;
                while(idx<sz && place[idx]==0){
                    idx++;
                }
                ans+=(idx-start+1)/2;
            }
        }
        return n<=ans;
    }
};