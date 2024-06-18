class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int,int>freq;
        for(int i=0;i<answers.size();i++){
            freq[answers[i]+1]++;
        }
        int ans=0;
        for(auto iter=freq.begin();iter!=freq.end();iter++){
            while(iter->second>0){
                iter->second-=iter->first;
                ans+=iter->first;
            }
        }
        return ans;
    }
};