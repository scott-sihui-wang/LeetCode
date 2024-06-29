class Solution {
public:
    bool isSelfDividing(int num){
        vector<int>div;
        int n=num;
        while(n>0){
            if(n%10==0){
                return false;
            }
            else{
                div.push_back(n%10);
            }
            n=n/10;
        }
        for(int i=0;i<div.size();i++){
            if(num%div[i]!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(isSelfDividing(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};