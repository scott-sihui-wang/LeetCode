class SummaryRanges {
public:
    set<int>s;
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        int start,prev;
        vector<vector<int>>ans;
        if(s.size()==0)return ans;
        for(set<int>::iterator iter=s.begin();iter!=s.end();iter++){
            if(iter==s.begin()){
                start=*iter;
                prev=*iter;
            }
            else{
                if(prev==*iter-1){
                    prev=*iter;
                }
                else{
                    ans.push_back({start,prev});
                    start=*iter;
                    prev=*iter;
                }
            }
        }
        ans.push_back({start,prev});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */