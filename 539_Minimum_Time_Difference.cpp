class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        bool slots[1440];
        memset(slots,false,sizeof(slots));
        int m_time=INT_MAX,M_time=INT_MIN;
        for(int i=0;i<timePoints.size();i++){
            int val=stoi(timePoints[i].substr(0,2))*60+stoi(timePoints[i].substr(3));
            if(slots[val])return 0;
            slots[val]=true;
            m_time=min(m_time,val);
            M_time=max(M_time,val);
        }
        int prev=-1;
        int diff=INT_MAX;
        for(int i=0;i<1440;i++){
            if(slots[i]){
                if(prev==-1){
                    prev=i;
                }
                else{
                    diff=min(diff,i-prev);
                    prev=i;
                }
            }
        }
        return min(diff,1440-(M_time-m_time));
    }
};