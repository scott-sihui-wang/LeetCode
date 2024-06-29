class Solution {
public:
    int maxNum(vector<int>& position, int d){
        int v=position[0];
        int i=1,ans=1;
        while(i<position.size()){
            while(i<position.size() && position[i]<v+d){
                i++;
            }
            if(i<position.size()){
                v=position[i];
                ans++;
            }
        }
        return ans;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int begin=1,end=position[position.size()-1]-position[0];
        int ans;
        while(begin<=end){
            int mid=(begin+end)/2;
            int res=maxNum(position,mid);
            if(res<m){
                end=mid-1;
            }
            else{
                ans=mid;
                begin=mid+1;
            }
        }
        return ans;
    }
};