class Solution {
public:
    map<int,int>dict;
    int size;
    Solution(int n, vector<int>& blacklist) {
        size=n-blacklist.size();
        sort(blacklist.begin(),blacklist.end());
        dict[0]=0;
        for(int i=0;i<blacklist.size();i++){
            dict[blacklist[i]-i]=i+1;
        }
    }
    
    int pick() {
        int num=rand()%size;
        for(map<int,int>::iterator iter=dict.begin();iter!=dict.end();iter++){
            iter++;
            map<int,int>::iterator iter2=iter;
            iter--;
            if(num>=iter->first && (iter2==dict.end() || num<iter2->first)){
                return num+iter->second;
            }
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */