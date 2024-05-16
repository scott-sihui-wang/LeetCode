class Solution {
public:
    static bool lessThan(pair<int,int>& A,pair<int,int>& B){
        return (A.first<B.first || (A.first==B.first && A.second>B.second));
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int,int>> v;
        for(int i=0;i<envelopes.size();i++){
            v.push_back({envelopes[i][0],envelopes[i][1]});
        }
        sort(v.begin(),v.end(),lessThan);
        vector<int> seq;
        for(int i=0;i<v.size();i++){
            if(seq.empty() ||(v[i].second>seq[seq.size()-1])){
                seq.push_back(v[i].second);
            }
            else{
                int begin=0,end=seq.size()-1;
                while(begin<=end){
                    int mid=(begin+end)/2;
                    if(seq[mid]>=v[i].second){
                        end=mid-1;
                    }
                    else{
                        begin=mid+1;
                    }
                }
                seq[begin]=v[i].second;
            }
        }
        return seq.size();
    }
};