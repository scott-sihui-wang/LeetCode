class SmallestInfiniteSet {
public:
    set<int>s;
    SmallestInfiniteSet() {
        for(int i=0;i<1000;i++){
            s.insert(i+1);
        }
    }
    
    int popSmallest() {
        int ans=*s.begin();
        s.erase(*s.begin());
        return ans;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */