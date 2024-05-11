class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> W_per_Q(quality.size());
        for(int i=0;i<quality.size();i++){
            W_per_Q[i]={wage[i]*1.0/quality[i],quality[i]};
        }
        sort(W_per_Q.begin(),W_per_Q.end());
        priority_queue<int> pq;
        int ttl_quality=0;
        double ans=DBL_MAX;
        for(int i=0;i<quality.size();i++){
            pq.push(W_per_Q[i].second);
            ttl_quality+=W_per_Q[i].second;
            if(pq.size()>k){
                ttl_quality-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=min(ans,ttl_quality*W_per_Q[i].first);
            }
        }
        return ans;
    }
};