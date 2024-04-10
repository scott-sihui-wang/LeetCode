class Solution {
public:
    int candy(vector<int>& ratings) {
        int len=ratings.size();
        if(len==1)return 1;
        int left[len],right[len];
        memset(left,0,sizeof(left));
        memset(right,0,sizeof(right));
        left[0]=1;
        for(int i=1;i<len;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }
            else{
                left[i]=1;
            }
        }
        right[len-1]=1;
        for(int i=len-1;i>0;i--){
            if(ratings[i-1]>ratings[i]){
                right[i-1]=right[i]+1;
            }
            else{
                right[i-1]=1;
            }
        }
        int ans=0;
        for(int i=0;i<len;i++){
            ans+=max(left[i],right[i]);
        }
        return ans;
    }
};