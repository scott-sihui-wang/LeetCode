class Solution {
public:
    string originalDigits(string s) {
        vector<string> dict={"zero","wto","ufor","xsi","geiht","three","five","inne","vseen","one"};
        vector<int> n={0,2,4,6,8,3,5,9,7,1};
        unordered_map<char,int>freq;
        multiset<int> nums;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;
        }
        for(int i=0;i<dict.size();i++){
            if(freq.find(dict[i][0])!=freq.end()){
                for(int j=0;j<freq[dict[i][0]];j++){
                    nums.insert(n[i]);
                }
                for(int j=1;j<dict[i].size();j++){
                    freq[dict[i][j]]-=freq[dict[i][0]];
                    if(freq[dict[i][j]]==0){
                        freq.erase(dict[i][j]);
                    }
                }
                freq.erase(dict[i][0]);
            }
        }
        string ans;
        for(set<int>::iterator iter=nums.begin();iter!=nums.end();iter++){
            ans+=(*iter+'0');
        }
        return ans;
    }
};