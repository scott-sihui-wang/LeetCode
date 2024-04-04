class Solution {
public:
    int countLargestGroup(int n) {
        int group[36];
        memset(group,0,sizeof(group));
        int max_size=0;
        int freq=0;
        for(int i=1;i<=n;i++){
            int sum=0;
            int tmp=i;
            while(tmp>0){
                sum+=tmp%10;
                tmp=tmp/10;
            }
            group[sum-1]++;
            if(group[sum-1]>max_size){
                max_size=group[sum-1];
                freq=0;
            }
            if(group[sum-1]==max_size){
                freq++;
            }
        }
        return freq;
    }
};