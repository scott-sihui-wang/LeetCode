class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)return false;
        map<int,int>cnt;
        for(int i=0;i<hand.size();i++){
            cnt[hand[i]]++;
        }
        while(cnt.size()>0){
            int num=cnt.begin()->first;
            int n=cnt.begin()->second;
            cnt.erase(num);
            for(int i=1;i<groupSize;i++){
                if(cnt.find(num+i)==cnt.end() || cnt[num+i]<n){
                    return false;
                }
                cnt[num+i]-=n;
                if(cnt[num+i]==0){
                    cnt.erase(num+i);
                }
            }
        }
        return true;
    }
};