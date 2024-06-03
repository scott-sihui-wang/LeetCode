class Solution {
public:
    struct compare{
        bool operator()(pair<int,string>& p1, pair<int,string>& p2){
            if(p1.first==p2.first)return p1.second<p2.second;
            return p1.first>p2.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>freq;
        for(int i=0;i<words.size();i++){
            freq[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;
        for(auto iter=freq.begin();iter!=freq.end();iter++){
            pq.push({iter->second,iter->first});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};