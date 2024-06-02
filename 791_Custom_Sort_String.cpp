class Solution {
public:
    struct compare{
        unordered_map<char,int>ord;
        compare(unordered_map<char,int>& m){
            ord=m;
        }
        bool operator()(char c1,char c2){
            return ord[c1]<ord[c2];
        }
    };
    string customSortString(string order, string s) {
        unordered_map<char,int>ord;
        for(int i=0;i<order.size();i++){
            ord[order[i]]=i;
        }
        sort(s.begin(),s.end(),compare(ord));
        return s;
    }
};