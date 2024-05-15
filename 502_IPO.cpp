class Solution {
public:
    static bool compare(pair<int,int>& p1,pair<int,int>& p2){//profit,capital
        if(p1.second==p2.second)return p1.first>p2.first;
        return p1.second<p2.second;
    }
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int,int>>v;
        for(int i=0;i<profits.size();i++){
            v.push_back({profits[i],capital[i]});
        }
        sort(v.begin(),v.end(),compare);
        priority_queue<int,vector<int>>pq;
        int i=0;
        while(k>0 && i<capital.size()){
            while(i<capital.size() && v[i].second<=w){
                if(v[i].first>0){
                    pq.push(v[i].first);
                }
                i++;
            }
            if(pq.empty()){
                break;
            }
            else{
                w+=pq.top();
                pq.pop();
                k--;
            }
        }
        while(k>0 && (!pq.empty())){
            w+=pq.top();
            pq.pop();
            k--;
        }
        return w;
    }
};