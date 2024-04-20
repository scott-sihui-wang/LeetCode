class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[2001];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<arr.size();i++){
            freq[arr[i]+1000]++;
        }
        unordered_set<int> uni_num;
        unordered_set<int>::iterator iter;
        for(int i=0;i<=2000;i++){
            if(freq[i]!=0){
                iter=uni_num.find(freq[i]);
                if(iter==uni_num.end()){
                    uni_num.insert(freq[i]);
                }
                else{
                    return false;
                }
            } 
        }
        return true;
    }
};