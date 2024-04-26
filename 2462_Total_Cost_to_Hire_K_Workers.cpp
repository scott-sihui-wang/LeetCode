class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        vector<pair<int,int>>cost_idx;
        for(int i=0;i<costs.size();i++){
            cost_idx.push_back({costs[i],i});
        }
        bool visited[costs.size()];
        memset(visited,false,sizeof(visited));
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q_first,q_last;
        for(int i=0;i<candidates;i++){
            q_first.push(cost_idx[i]);
            q_last.push(cost_idx[costs.size()-1-i]);
        }
        int idx_first=candidates-1,idx_last=costs.size()-candidates;
        for(int i=0;i<k;i++){
            pair<int,int> cand1=q_first.top();
            pair<int,int> cand2=q_last.top();
            if(idx_first+1<=costs.size()-1 && idx_last-1>=0){    
                if(cand1.first<cand2.first || (cand1.first==cand2.first && cand1.second<cand2.second)){
                    q_first.pop();
                    ans+=cand1.first;
                    visited[cand1.second]=true;
                    while(idx_first+1<=costs.size()-1 && visited[idx_first+1]==true){
                        idx_first++;
                    }
                    if(idx_first+1<=costs.size()-1){
                        q_first.push(cost_idx[idx_first+1]);
                        idx_first++;
                    }
                }
                else if(cand1.first>cand2.first || (cand1.first==cand2.first && cand1.second>cand1.second)){
                    q_last.pop();
                    ans+=cand2.first;
                    visited[cand2.second]=true;
                    while(idx_last-1>=0 && visited[idx_last-1]==true){
                        idx_last--;
                    }
                    if(idx_last-1>=0){
                        q_last.push(cost_idx[idx_last-1]);
                        idx_last--;
                    }
                }
                else{
                    q_first.pop();
                    q_last.pop();
                    ans+=cand1.first;
                    visited[cand1.second]=true;
                    while(idx_first+1<=costs.size()-1 && visited[idx_first+1]==true){
                        idx_first++;
                    }
                    if(idx_first+1<=costs.size()-1){
                        q_first.push(cost_idx[idx_first+1]);
                        idx_first++;
                    }
                    while(idx_last-1>=0 && visited[idx_last-1]==true){
                        idx_last--;
                    }
                    if(idx_last-1>=0){
                        q_last.push(cost_idx[idx_last-1]);
                        idx_last--;
                    }
                }
            }
            else if(idx_first+1<=costs.size()-1){
                q_last.pop();
                ans+=cand2.first;
            }
            else{
                q_first.pop();
                ans+=cand1.first;
            }
        }
        return ans;
    }
};