class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp1,mp2;
        for(int i=0;i<s.size();i++){
            if(mp1.find(s[i])==mp1.end()){
                mp1[s[i]]=i;
                mp2[s[i]]=i;
            }
            else{
                mp2[s[i]]=i;
            }
        }
        vector<pair<int,int>>intervals;
        unordered_map<char,int>::iterator iter;
        for(iter=mp1.begin();iter!=mp1.end();iter++){
            intervals.push_back({iter->second,mp2[iter->first]});
        }
        sort(intervals.begin(),intervals.end());
        vector<int> ans;
        int left=0;
        int right=intervals[0].second;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].first<right){
                right=max(right,intervals[i].second);
            }
            else{
                ans.push_back(right-left+1);
                left=intervals[i].first;
                right=intervals[i].second;
            }
        }
        ans.push_back(right-left+1);
        return ans;
    }
};