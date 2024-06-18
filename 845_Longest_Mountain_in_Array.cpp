class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int riseStart=-1,peak=-1,len=0;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]>arr[i]){
                if(riseStart==-1){
                    riseStart=i;
                }
                else if(peak!=-1){
                    len=max(len,i-riseStart+1);
                    riseStart=i;
                    peak=-1;
                }
            }
            else if(arr[i+1]==arr[i]){
                if(riseStart!=-1 && peak==-1){
                    riseStart=-1;
                }
                else if(peak!=-1){
                    len=max(len,i-riseStart+1);
                    riseStart=-1;
                    peak=-1;
                }
            }
            else{
                if(riseStart!=-1 && peak==-1){
                    peak=i;
                }
            }
        }
        if(riseStart!=-1 && peak!=-1){
            len=max(len,(int)arr.size()-riseStart);
        }
        return len;
    }
};