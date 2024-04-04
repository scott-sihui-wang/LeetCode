class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        digits[len-1]++;
        int overflow=digits[len-1]/10;
        digits[len-1]=digits[len-1]%10;
        int i=len-2;
        while(i>=0 && overflow!=0){
            digits[i]+=overflow;
            overflow=digits[i]/10;
            digits[i]=digits[i]%10;
            i--;
        }
        if(overflow==0){
            return digits;
        }
        else{
            vector<int> sol;
            sol.push_back(overflow);
            sol.insert(sol.end(),digits.begin(),digits.end());
            return sol;
        }
    }
};