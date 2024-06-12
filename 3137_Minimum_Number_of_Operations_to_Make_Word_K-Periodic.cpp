class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string,int>freq;
        int i=0;
        int max_freq=0;
        while(i<word.size()){
            string substring=word.substr(i,k);
            freq[substring]++;
            max_freq=max(max_freq,freq[substring]);
            i+=k;
        }
        return word.size()/k-max_freq;
    }
};