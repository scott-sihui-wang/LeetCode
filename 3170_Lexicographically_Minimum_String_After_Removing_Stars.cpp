class Solution {
public:
    struct compare{
        bool operator()(pair<char,int>& p1, pair<char,int>& p2){
            if(p1.first==p2.first)return p1.second<p2.second;
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        string ans=string("");
        priority_queue<pair<char,int>,vector<pair<char,int>>,compare>pq;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                pq.push({s[i],i});
            }
            else{
                pq.pop();
            }
        }
        vector<pair<int,char>>v;
        while(!pq.empty()){
            v.push_back({pq.top().second,pq.top().first});
            pq.pop();
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            ans+=v[i].second;
        }
        return ans;
    }
};