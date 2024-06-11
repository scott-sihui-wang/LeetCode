class MyCalendarTwo {
public:
    multiset<pair<int,int>>booked;
    set<pair<int,int>>intersection;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(auto iter=intersection.begin();iter!=intersection.end() && iter->first<end;iter++){
            if(start<iter->second){
                return false;
            }
        }
        for(auto iter=booked.begin();iter!=booked.end() && iter->first<end;iter++){
            if(start<iter->second){
                intersection.insert({max(start,iter->first),min(end,iter->second)});
            }
        }
        booked.insert({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */