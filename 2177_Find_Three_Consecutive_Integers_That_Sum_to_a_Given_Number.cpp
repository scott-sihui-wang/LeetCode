class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>sol;
        if(num%3!=0){
            return sol;
        }
        else{
            sol.push_back(num/3-1);
            sol.push_back(num/3);
            sol.push_back(num/3+1);
            return sol;
        }
    }
};